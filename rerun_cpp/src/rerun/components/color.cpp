// DO NOT EDIT!: This file was auto-generated by crates/re_types_builder/src/codegen/cpp/mod.rs:54.
// Based on "crates/re_types/definitions/rerun/components/color.fbs".

#include "color.hpp"

#include "../arrow.hpp"
#include "../datatypes/color.hpp"

#include <arrow/builder.h>
#include <arrow/table.h>
#include <arrow/type_fwd.h>

namespace rerun {
    namespace components {
        const char Color::NAME[] = "rerun.colorrgba";

        const std::shared_ptr<arrow::DataType> &Color::arrow_datatype() {
            static const auto datatype = rerun::datatypes::Color::arrow_datatype();
            return datatype;
        }

        Result<std::shared_ptr<arrow::UInt32Builder>> Color::new_arrow_array_builder(
            arrow::MemoryPool *memory_pool
        ) {
            if (!memory_pool) {
                return Error(ErrorCode::UnexpectedNullArgument, "Memory pool is null.");
            }

            return Result(rerun::datatypes::Color::new_arrow_array_builder(memory_pool).value);
        }

        Error Color::fill_arrow_array_builder(
            arrow::UInt32Builder *builder, const Color *elements, size_t num_elements
        ) {
            if (!builder) {
                return Error(ErrorCode::UnexpectedNullArgument, "Passed array builder is null.");
            }
            if (!elements) {
                return Error(
                    ErrorCode::UnexpectedNullArgument,
                    "Cannot serialize null pointer to arrow array."
                );
            }

            static_assert(sizeof(rerun::datatypes::Color) == sizeof(Color));
            RR_RETURN_NOT_OK(rerun::datatypes::Color::fill_arrow_array_builder(
                builder,
                reinterpret_cast<const rerun::datatypes::Color *>(elements),
                num_elements
            ));

            return Error::ok();
        }

        Result<rerun::DataCell> Color::to_data_cell(const Color *instances, size_t num_instances) {
            // TODO(andreas): Allow configuring the memory pool.
            arrow::MemoryPool *pool = arrow::default_memory_pool();

            auto builder_result = Color::new_arrow_array_builder(pool);
            RR_RETURN_NOT_OK(builder_result.error);
            auto builder = std::move(builder_result.value);
            if (instances && num_instances > 0) {
                RR_RETURN_NOT_OK(
                    Color::fill_arrow_array_builder(builder.get(), instances, num_instances)
                );
            }
            std::shared_ptr<arrow::Array> array;
            ARROW_RETURN_NOT_OK(builder->Finish(&array));

            auto schema =
                arrow::schema({arrow::field(Color::NAME, Color::arrow_datatype(), false)});

            rerun::DataCell cell;
            cell.component_name = Color::NAME;
            const auto ipc_result = rerun::ipc_from_table(*arrow::Table::Make(schema, {array}));
            RR_RETURN_NOT_OK(ipc_result.error);
            cell.buffer = std::move(ipc_result.value);

            return cell;
        }
    } // namespace components
} // namespace rerun
