// DO NOT EDIT!: This file was auto-generated by crates/re_types_builder/src/codegen/cpp/mod.rs:54.
// Based on "crates/re_types/definitions/rerun/archetypes/depth_image.fbs".

#include "depth_image.hpp"

#include "../indicator_component.hpp"

namespace rerun {
    namespace archetypes {
        const char DepthImage::INDICATOR_COMPONENT_NAME[] = "rerun.components.DepthImageIndicator";

        std::vector<AnonymousComponentBatch> DepthImage::as_component_batches() const {
            std::vector<AnonymousComponentBatch> comp_batches;
            comp_batches.reserve(3);

            comp_batches.emplace_back(data);
            if (meter.has_value()) {
                comp_batches.emplace_back(meter.value());
            }
            if (draw_order.has_value()) {
                comp_batches.emplace_back(draw_order.value());
            }
            comp_batches.emplace_back(
                ComponentBatch<
                    components::IndicatorComponent<DepthImage::INDICATOR_COMPONENT_NAME>>(
                    nullptr,
                    num_instances()
                )
            );

            return comp_batches;
        }
    } // namespace archetypes
} // namespace rerun
