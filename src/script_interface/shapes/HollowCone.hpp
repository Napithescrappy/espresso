/*
 * Copyright (C) 2010-2018 The ESPResSo project
 * Copyright (C) 2002,2003,2004,2005,2006,2007,2008,2009,2010
 *   Max-Planck-Institute for Polymer Research, Theory Group
 *
 * This file is part of ESPResSo.
 *
 * ESPResSo is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * ESPResSo is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef SCRIPT_INTERFACE_SHAPES_HOLLOWCONE_HPP
#define SCRIPT_INTERFACE_SHAPES_HOLLOWCONE_HPP

#include "Shape.hpp"
#include "core/shapes/HollowCone.hpp"

namespace ScriptInterface {
namespace Shapes {

class HollowCone : public Shape {
public:
  HollowCone() : m_hollowcone(new ::Shapes::HollowCone()) {
    add_parameters(
        {{"center",
          [this](Variant const &v) {
            m_hollowcone->set_position(get_value<Utils::Vector3d>(v));
          },
          [this]() { return m_hollowcone->position(); }},
         {"axis",
          [this](Variant const &v) {
            m_hollowcone->set_orientation(get_value<Utils::Vector3d>(v));
          },
          [this]() { return m_hollowcone->orientation(); }},
         {"outer_radius", m_hollowcone->outer_radius()},
         {"inner_radius", m_hollowcone->inner_radius()},
         {"width", m_hollowcone->width()},
         {"opening_angle", m_hollowcone->opening_angle()},
         {"direction", m_hollowcone->direction()}});
  }

  std::shared_ptr<::Shapes::Shape> shape() const override {
    return m_hollowcone;
  }

private:
  std::shared_ptr<::Shapes::HollowCone> m_hollowcone;
};

} /* namespace Shapes */
} /* namespace ScriptInterface */

#endif
