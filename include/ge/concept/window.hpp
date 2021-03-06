#pragma once

#include <boost/concept_check.hpp>

#include <glm/glm.hpp>

#include <boost/signals2.hpp>

namespace ge
{
namespace concept
{
// the concept for subsystems
template <typename X>
struct Window
{
	BOOST_CONCEPT_USAGE(Window)
	{
		i.set_title("New title");
		std::string title = i_c.get_title();

		i.set_size(glm::uvec2(100, 200));
		glm::uvec2 size = i_c.get_size();
	}

private:
	X i;
	const X i_c;
};

}  // namespace concept

}  // namespace ge
