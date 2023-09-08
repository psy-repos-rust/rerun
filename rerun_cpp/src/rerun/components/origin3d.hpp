// DO NOT EDIT!: This file was auto-generated by crates/re_types_builder/src/codegen/cpp/mod.rs:54.
// Based on "crates/re_types/definitions/rerun/components/origin3d.fbs".

#pragma once

#include "../data_cell.hpp"
#include "../datatypes/vec3d.hpp"
#include "../result.hpp"

#include <cstdint>
#include <memory>
#include <utility>

namespace arrow {
    class DataType;
    class FixedSizeListBuilder;
    class MemoryPool;
} // namespace arrow

namespace rerun {
    namespace components {
        /// A point of origin in 3D space.
        struct Origin3D {
            rerun::datatypes::Vec3D origin;

            /// Name of the component, used for serialization.
            static const char NAME[];

          public:
            // Extensions to generated type defined in 'origin3d_ext.cpp'

            /// Construct Origin3D from x/y/z values.
            Origin3D(float x, float y, float z) : origin{x, y, z} {}

            float x() const {
                return origin.x();
            }

            float y() const {
                return origin.y();
            }

            float z() const {
                return origin.z();
            }

          public:
            Origin3D() = default;

            Origin3D(rerun::datatypes::Vec3D _origin) : origin(std::move(_origin)) {}

            Origin3D& operator=(rerun::datatypes::Vec3D _origin) {
                origin = std::move(_origin);
                return *this;
            }

            Origin3D(const float (&arg)[3]) : origin(arg) {}

            /// Returns the arrow data type this type corresponds to.
            static const std::shared_ptr<arrow::DataType>& arrow_datatype();

            /// Creates a new array builder with an array of this type.
            static Result<std::shared_ptr<arrow::FixedSizeListBuilder>> new_arrow_array_builder(
                arrow::MemoryPool* memory_pool
            );

            /// Fills an arrow array builder with an array of this type.
            static Error fill_arrow_array_builder(
                arrow::FixedSizeListBuilder* builder, const Origin3D* elements, size_t num_elements
            );

            /// Creates a Rerun DataCell from an array of Origin3D components.
            static Result<rerun::DataCell> to_data_cell(
                const Origin3D* instances, size_t num_instances
            );
        };
    } // namespace components
} // namespace rerun
