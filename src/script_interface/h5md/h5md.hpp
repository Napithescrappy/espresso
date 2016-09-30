/*
  Copyright (C) 2010,2011,2012,2013,2014 The ESPResSo project
  Copyright (C) 2002,2003,2004,2005,2006,2007,2008,2009,2010
  Max-Planck-Institute for Polymer Research, Theory Group

  This file is part of ESPResSo.

  ESPResSo is free software: you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation, either version 3 of the License, or
  (at your option) any later version.

  ESPResSo is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.

  You should have received a copy of the GNU General Public License
  along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#ifndef ESPRESSO_SCRIPTINTERFACE_H5MD_HPP
#define ESPRESSO_SCRIPTINTERFACE_H5MD_HPP

#include "ScriptInterface.hpp"
#include "io/writer/h5md/h5md_core.hpp"


namespace ScriptInterface {
namespace Writer {

class H5mdScript : public ScriptInterfaceBase {
    public:
        H5mdScript() : m_h5md(new ::Writer::H5md::File()) {}
        // Returns the name of the class
        const std::string name() const override { 
            return "ScriptInterface::Writer::H5mdScript";
        };
        
        ParameterMap valid_parameters() const override {
            return {{"filename", {ParameterType::STRING, true}},
                    {"scriptname", {ParameterType::STRING, true}}};
        };

        VariantMap get_parameters() const override {
            return {{"filename", m_h5md->filename()},
                    {"scriptname", m_h5md->scriptname()}};
        };
        
        void set_parameter(const std::string &name, const Variant &value) override {
            SET_PARAMETER_HELPER("filename", m_h5md->filename());
            SET_PARAMETER_HELPER("scriptname", m_h5md->scriptname());
        };

        Variant call_method(const std::string &name,
                            const VariantMap &parameters) override {
            if (name == "init_file") m_h5md->InitFile();
            else if (name == "write") m_h5md->Write(1);
            else if (name == "close") m_h5md->Close();
            return {};
        }
    private:
        std::shared_ptr<::Writer::H5md::File> m_h5md;
};

} /* namespace Writer */
} /* namespace Scriptinterface */


#endif //ESPRESSO_H5MD_HPP
