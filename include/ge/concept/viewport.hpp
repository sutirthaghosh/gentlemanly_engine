#pragma once

#include <boost/concept_check.hpp>

#include <glm/glm.hpp>

#include "ge/input_event.hpp"

#include <memory>

namespace ge
{
struct camera_component;
struct model_system;
namespace concept
{
template <typename X>
struct Viewport
{
	BOOST_CONCEPT_USAGE(Viewport)
	{
		const X& i_c = i;

		i.set_background_color(glm::vec4{});

		// this should be a Window<>
		auto& win = i_c.get_window();
		
		input_event ev = i.get_next_input_event();
	}

private:
	X i;
};

}  // namespace concept

}  // namespace ge
