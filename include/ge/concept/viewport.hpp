#pragma once

#include <boost/concept_check.hpp>

#include "ge/actor.hpp"
#include "ge/camera.hpp"

namespace ge
{
namespace concept
{
// we only want to document the basic class that implements it
#ifndef DOXYGEN_SHOULD_SKIP_THIS

template <typename X>
struct Viewport
{
	BOOST_CONCEPT_USAGE(Viewport)
	{
		i.set_background_color(glm::vec4{});

		i.render();

		actor* root_actor = i.root_actor();
		const actor* root_actor_c = i_c.root_actor();

		i.set_camera(new camera(root_actor));
		camera* cam = i_c.get_camera();
	}

private:
	X i;
	const X i_c;
};

#else
// for doxygen only

/**
 * The concept for the viewport.
 *
 * To check if a class is a conforming Viewport, use BOOST_CONCEPT_ASSERT(ge::concept::Viewport<X>).
 *
 * A viewport is an object that represents somewhere on a Window that is drawable. For many
 * window_backend implemtations, like SDL,
 * this is just the entire window, but others not. For example, the Qt window_backend implements
 * Viewport as a QOpenGLWidget.
 */
struct Viewport
{
	/**
	 * Sets the color of the background of the viewport.
	 */
	set_background_color(glm::vec4);
}

#endif

}  // namespace concept

}  // namespace ge
