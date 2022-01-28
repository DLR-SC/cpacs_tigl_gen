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

#include <string>
#include <tixi.h>
#include "tigl_internal.h"

namespace tigl
{
class CTiglUIDObject;

namespace generated
{
    // This class is used in:
    /// @brief Summary
    /// 
    /// The C ommon P arametric A ircraft C onfiguration S cheme (CPACS) is an XML-based data format for describing aircraft configurations and their corresponding data.
    /// This XML-Schema document ( XSD ) serves two purposes: (1) it defines the CPACS data structure used in the XML file (e.g., aircraft.xml) and
    /// (2) it provides the corresponding documentation (see picture below). An XML processor (e.g., TiXI https://github.com/DLR-SC/tixi or
    /// XML tools in Eclipse) parses the XSD and XML files and validates whether the data set defined by the user (or tool) conforms to the given structure defined by the schema.
    /// This documentation explains the elements defined in CPACS and its corresponding data types .
    /// Data types can either be simple types (string, double, boolean, etc.) or complex types (definition of attributes and sub-elements to build a hierarchical
    /// structure). In addition, the sequence of the elements and their occurrence is documented.
    /// To link the XML file to the XSD file, the header of the XML file should specify the path of the schema file.
    /// An example could look like this:
    /// &lt;cpacs xmlns:xsi="http://www.w3.org/2001/XMLSchema-instance"
    /// xsi:noNamespaceSchemaLocation="pathToSchemaFile/cpacs_schema.xsd"&gt;
    /// 
    /// CPACS is an open source project published by the German Aerospace Center (DLR e.V.) https://www.dlr.de/ . For further information please visit www.cpacs.de https://www.cpacs.de .
    /// 
    class CPACSRoot
    {
    public:
        TIGL_EXPORT CPACSRoot();
        TIGL_EXPORT virtual ~CPACSRoot();

        TIGL_EXPORT virtual CTiglUIDObject* GetNextUIDParent();
        TIGL_EXPORT virtual const CTiglUIDObject* GetNextUIDParent() const;

        TIGL_EXPORT virtual void ReadCPACS(const TixiDocumentHandle& tixiHandle, const std::string& xpath);
        TIGL_EXPORT virtual void WriteCPACS(const TixiDocumentHandle& tixiHandle, const std::string& xpath) const;

        TIGL_EXPORT virtual const int& GetC() const;
        TIGL_EXPORT virtual void SetC(const int& value);

        TIGL_EXPORT virtual const int& GetA() const;
        TIGL_EXPORT virtual void SetA(const int& value);

        TIGL_EXPORT virtual const int& GetB() const;
        TIGL_EXPORT virtual void SetB(const int& value);

    protected:
        /// attribute documentation
        int m_c;

        /// element documentation with b o ld
        int m_a;

        int m_b;

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
        : m_c(0)
        , m_a(0)
        , m_b(0)
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
        // read attribute c
        if (tixi::TixiCheckAttribute(tixiHandle, xpath, "c")) {
            m_c = tixi::TixiGetAttribute<int>(tixiHandle, xpath, "c");
        }
        else {
            LOG(ERROR) << "Required attribute c is missing at xpath " << xpath;
        }

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
        else {
            LOG(ERROR) << "Required element b is missing at xpath " << xpath;
        }

    }

    void CPACSRoot::WriteCPACS(const TixiDocumentHandle& tixiHandle, const std::string& xpath) const
    {
        // write attribute c
        tixi::TixiSaveAttribute(tixiHandle, xpath, "c", m_c);

        // write element a
        tixi::TixiCreateElementIfNotExists(tixiHandle, xpath + "/a");
        tixi::TixiSaveElement(tixiHandle, xpath + "/a", m_a);

        // write element b
        tixi::TixiCreateElementIfNotExists(tixiHandle, xpath + "/b");
        tixi::TixiSaveElement(tixiHandle, xpath + "/b", m_b);

    }

    const int& CPACSRoot::GetC() const
    {
        return m_c;
    }

    void CPACSRoot::SetC(const int& value)
    {
        m_c = value;
    }

    const int& CPACSRoot::GetA() const
    {
        return m_a;
    }

    void CPACSRoot::SetA(const int& value)
    {
        m_a = value;
    }

    const int& CPACSRoot::GetB() const
    {
        return m_b;
    }

    void CPACSRoot::SetB(const int& value)
    {
        m_b = value;
    }

} // namespace generated
} // namespace tigl
