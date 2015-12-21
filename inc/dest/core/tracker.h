/**
 This file is part of Deformable Shape Tracking (DEST).
 
 Copyright Christoph Heindl 2015
 
 Deformable Shape Tracking is free software: you can redistribute it and/or modify
 it under the terms of the GNU General Public License as published by
 the Free Software Foundation, either version 3 of the License, or
 (at your option) any later version.
 
 Deformable Shape Tracking is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 GNU General Public License for more details.
 
 You should have received a copy of the GNU General Public License
 along with Deformable Shape Tracking. If not, see <http://www.gnu.org/licenses/>.
*/

#ifndef DEST_TRACKER_H
#define DEST_TRACKER_H

#include <dest/core/image.h>
#include <dest/core/shape.h>
#include <dest/core/training_data.h>
#include <dest/io/dest_io_generated.h>
#include <memory>
#include <string>

namespace dest {
    namespace core {
        
        class Tracker {
        public:
            Tracker();
            ~Tracker();
            Tracker(const Tracker &other);
            
            bool fit(TrainingData &t);
            
            Shape predict(const Image &img, const Shape &shape) const;

            Shape initialShapeFromRect(const Shape &rect) const;

            flatbuffers::Offset<io::Tracker> save(flatbuffers::FlatBufferBuilder &fbb) const;
            void load(const io::Tracker &fbs);

            bool save(const std::string &path) const;
            bool load(const std::string &path);
            
        private:

            Shape boundingBoxCornersOfShape(const Shape &s) const;

            struct data;
            std::unique_ptr<data> _data;
        };
        
    }
}

#endif