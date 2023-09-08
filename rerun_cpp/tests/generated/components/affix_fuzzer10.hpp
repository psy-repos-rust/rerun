// DO NOT EDIT!: This file was auto-generated by crates/re_types_builder/src/codegen/cpp/mod.rs:54.
// Based on "crates/re_types/definitions/rerun/testing/components/fuzzy.fbs".

#pragma once

#include <cstdint>
#include <memory>
#include <optional>
#include <rerun/data_cell.hpp>
#include <rerun/result.hpp>
#include <string>
#include <utility>

namespace arrow {
    class DataType;
    class MemoryPool;
    class StringBuilder;
} // namespace arrow

namespace rerun {
    namespace components {
        struct AffixFuzzer10 {
            std::optional<std::string> single_string_optional;

            /// Name of the component, used for serialization.
            static const char NAME[];

          public:
            AffixFuzzer10() = default;

            AffixFuzzer10(std::optional<std::string> _single_string_optional)
                : single_string_optional(std::move(_single_string_optional)) {}

            AffixFuzzer10& operator=(std::optional<std::string> _single_string_optional) {
                single_string_optional = std::move(_single_string_optional);
                return *this;
            }

            /// Returns the arrow data type this type corresponds to.
            static const std::shared_ptr<arrow::DataType>& arrow_datatype();

            /// Creates a new array builder with an array of this type.
            static Result<std::shared_ptr<arrow::StringBuilder>> new_arrow_array_builder(
                arrow::MemoryPool* memory_pool
            );

            /// Fills an arrow array builder with an array of this type.
            static Error fill_arrow_array_builder(
                arrow::StringBuilder* builder, const AffixFuzzer10* elements, size_t num_elements
            );

            /// Creates a Rerun DataCell from an array of AffixFuzzer10 components.
            static Result<rerun::DataCell> to_data_cell(
                const AffixFuzzer10* instances, size_t num_instances
            );
        };
    } // namespace components
} // namespace rerun
