// Copyright (c) 2020 RISC Software GmbH
//
// This file was generated by CPACSGen from CPACS XML Schema (c) German Aerospace Center (DLR/SC).
// Do not edit, all changes are lost when files are re-generated.
//
// Licensed under the Apache License, Version 2.0 (the "License")
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#pragma once

#include <boost/optional.hpp>
#include <boost/utility/in_place_factory.hpp>
#include <string>
#include <tixi.h>
#include "tigl_internal.h"

namespace tigl
{
class CTiglUIDObject;

namespace generated
{
    // This class is used in:
    class CPACSRoot
    {
    public:
        TIGL_EXPORT CPACSRoot();
        TIGL_EXPORT virtual ~CPACSRoot();

        TIGL_EXPORT virtual CTiglUIDObject* GetNextUIDParent();
        TIGL_EXPORT virtual const CTiglUIDObject* GetNextUIDParent() const;

        TIGL_EXPORT virtual void ReadCPACS(const TixiDocumentHandle& tixiHandle, const std::string& xpath);
        TIGL_EXPORT virtual void WriteCPACS(const TixiDocumentHandle& tixiHandle, const std::string& xpath) const;

        TIGL_EXPORT virtual const int& GetA() const;
        TIGL_EXPORT virtual void SetA(const int& value);

        TIGL_EXPORT virtual const boost::optional<int>& GetB() const;
        TIGL_EXPORT virtual void SetB(const boost::optional<int>& value);

        TIGL_EXPORT virtual const int& GetC() const;
        TIGL_EXPORT virtual void SetC(const int& value);

        TIGL_EXPORT virtual const int& GetD() const;
        TIGL_EXPORT virtual void SetD(const int& value);

        TIGL_EXPORT virtual const boost::optional<int>& GetE() const;
        TIGL_EXPORT virtual void SetE(const boost::optional<int>& value);

        TIGL_EXPORT virtual const int& GetF() const;
        TIGL_EXPORT virtual void SetF(const int& value);

    protected:
        int                  m_a;
        boost::optional<int> m_b;
        int                  m_c;
        int                  m_d;
        boost::optional<int> m_e;
        int                  m_f;

    private:
        CPACSRoot(const CPACSRoot&) = delete;
        CPACSRoot& operator=(const CPACSRoot&) = delete;

        CPACSRoot(CPACSRoot&&) = delete;
        CPACSRoot& operator=(CPACSRoot&&) = delete;
    };
} // namespace generated

// Aliases in tigl namespace
using CCPACSRoot = generated::CPACSRoot;
} // namespace tigl
// Copyright (c) 2020 RISC Software GmbH
//
// This file was generated by CPACSGen from CPACS XML Schema (c) German Aerospace Center (DLR/SC).
// Do not edit, all changes are lost when files are re-generated.
//
// Licensed under the Apache License, Version 2.0 (the "License")
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#include "CPACSRoot.h"
#include "CTiglError.h"
#include "CTiglLogging.h"
#include "CTiglUIDObject.h"
#include "TixiHelper.h"

namespace tigl
{
namespace generated
{
    CPACSRoot::CPACSRoot()
        : m_a(0)
        , m_c(0)
        , m_d(0)
        , m_f(0)
    {
    }

    CPACSRoot::~CPACSRoot()
    {
    }

    const CTiglUIDObject* CPACSRoot::GetNextUIDParent() const
    {
        return nullptr;
    }

    CTiglUIDObject* CPACSRoot::GetNextUIDParent()
    {
        return nullptr;
    }

    void CPACSRoot::ReadCPACS(const TixiDocumentHandle& tixiHandle, const std::string& xpath)
    {
        // read element a
        if (tixi::TixiCheckElement(tixiHandle, xpath + "/a")) {
            m_a = tixi::TixiGetElement<int>(tixiHandle, xpath + "/a");
        }
        else {
            LOG(ERROR) << "Required element a is missing at xpath " << xpath;
        }

        // read element b
        if (tixi::TixiCheckElement(tixiHandle, xpath + "/b")) {
            m_b = tixi::TixiGetElement<int>(tixiHandle, xpath + "/b");
        }

        // read element c
        if (tixi::TixiCheckElement(tixiHandle, xpath + "/c")) {
            m_c = tixi::TixiGetElement<int>(tixiHandle, xpath + "/c");
        }
        else {
            LOG(ERROR) << "Required element c is missing at xpath " << xpath;
        }

        // read element d
        if (tixi::TixiCheckElement(tixiHandle, xpath + "/d")) {
            m_d = tixi::TixiGetElement<int>(tixiHandle, xpath + "/d");
        }
        else {
            LOG(ERROR) << "Required element d is missing at xpath " << xpath;
        }

        // read element e
        if (tixi::TixiCheckElement(tixiHandle, xpath + "/e")) {
            m_e = tixi::TixiGetElement<int>(tixiHandle, xpath + "/e");
        }

        // read element f
        if (tixi::TixiCheckElement(tixiHandle, xpath + "/f")) {
            m_f = tixi::TixiGetElement<int>(tixiHandle, xpath + "/f");
        }
        else {
            LOG(ERROR) << "Required element f is missing at xpath " << xpath;
        }

    }

    void CPACSRoot::WriteCPACS(const TixiDocumentHandle& tixiHandle, const std::string& xpath) const
    {
        // write element a
        tixi::TixiCreateElementIfNotExists(tixiHandle, xpath + "/a");
        tixi::TixiSaveElement(tixiHandle, xpath + "/a", m_a);

        // write element b
        if (m_b) {
            tixi::TixiCreateElementIfNotExists(tixiHandle, xpath + "/b");
            tixi::TixiSaveElement(tixiHandle, xpath + "/b", *m_b);
        }
        else {
            if (tixi::TixiCheckElement(tixiHandle, xpath + "/b")) {
                tixi::TixiRemoveElement(tixiHandle, xpath + "/b");
            }
        }

        // write element c
        tixi::TixiCreateElementIfNotExists(tixiHandle, xpath + "/c");
        tixi::TixiSaveElement(tixiHandle, xpath + "/c", m_c);

        // write element d
        tixi::TixiCreateElementIfNotExists(tixiHandle, xpath + "/d");
        tixi::TixiSaveElement(tixiHandle, xpath + "/d", m_d);

        // write element e
        if (m_e) {
            tixi::TixiCreateElementIfNotExists(tixiHandle, xpath + "/e");
            tixi::TixiSaveElement(tixiHandle, xpath + "/e", *m_e);
        }
        else {
            if (tixi::TixiCheckElement(tixiHandle, xpath + "/e")) {
                tixi::TixiRemoveElement(tixiHandle, xpath + "/e");
            }
        }

        // write element f
        tixi::TixiCreateElementIfNotExists(tixiHandle, xpath + "/f");
        tixi::TixiSaveElement(tixiHandle, xpath + "/f", m_f);

    }

    const int& CPACSRoot::GetA() const
    {
        return m_a;
    }

    void CPACSRoot::SetA(const int& value)
    {
        m_a = value;
    }

    const boost::optional<int>& CPACSRoot::GetB() const
    {
        return m_b;
    }

    void CPACSRoot::SetB(const boost::optional<int>& value)
    {
        m_b = value;
    }

    const int& CPACSRoot::GetC() const
    {
        return m_c;
    }

    void CPACSRoot::SetC(const int& value)
    {
        m_c = value;
    }

    const int& CPACSRoot::GetD() const
    {
        return m_d;
    }

    void CPACSRoot::SetD(const int& value)
    {
        m_d = value;
    }

    const boost::optional<int>& CPACSRoot::GetE() const
    {
        return m_e;
    }

    void CPACSRoot::SetE(const boost::optional<int>& value)
    {
        m_e = value;
    }

    const int& CPACSRoot::GetF() const
    {
        return m_f;
    }

    void CPACSRoot::SetF(const int& value)
    {
        m_f = value;
    }

} // namespace generated
} // namespace tigl
