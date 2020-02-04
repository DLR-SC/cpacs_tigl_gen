// Copyright (c) 2018 RISC Software GmbH
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
class CTiglUIDManager;

namespace generated
{
    class CPACSTypeA;

    // This class is used in:
    // CPACSTypeA

    // generated from /xsd:schema/xsd:complexType[1]
    class CPACSBase
    {
    public:
        TIGL_EXPORT CPACSBase(CPACSTypeA* parent, CTiglUIDManager* uidMgr);

        TIGL_EXPORT virtual ~CPACSBase();

        TIGL_EXPORT CPACSTypeA* GetParent();

        TIGL_EXPORT const CPACSTypeA* GetParent() const;

        TIGL_EXPORT CTiglUIDManager& GetUIDManager();
        TIGL_EXPORT const CTiglUIDManager& GetUIDManager() const;

        TIGL_EXPORT virtual void ReadCPACS(const TixiDocumentHandle& tixiHandle, const std::string& xpath);
        TIGL_EXPORT virtual void WriteCPACS(const TixiDocumentHandle& tixiHandle, const std::string& xpath) const;

        TIGL_EXPORT virtual const std::string& GetUID() const;
        TIGL_EXPORT virtual void SetUID(const std::string& value);

    protected:
        CPACSTypeA* m_parent;

        CTiglUIDManager* m_uidMgr;

        std::string m_uID;

    private:
        CPACSBase(const CPACSBase&) = delete;
        CPACSBase& operator=(const CPACSBase&) = delete;

        CPACSBase(CPACSBase&&) = delete;
        CPACSBase& operator=(CPACSBase&&) = delete;
    };
} // namespace generated

// Aliases in tigl namespace
using CCPACSBase = generated::CPACSBase;
using CCPACSTypeA = generated::CPACSTypeA;
} // namespace tigl
// Copyright (c) 2018 RISC Software GmbH
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

#include <cassert>
#include "CPACSBase.h"
#include "CPACSTypeA.h"
#include "CTiglError.h"
#include "CTiglLogging.h"
#include "CTiglUIDManager.h"
#include "TixiHelper.h"

namespace tigl
{
namespace generated
{
    CPACSBase::CPACSBase(CPACSTypeA* parent, CTiglUIDManager* uidMgr)
        : m_uidMgr(uidMgr)
    {
        //assert(parent != NULL);
        m_parent = parent;
    }

    CPACSBase::~CPACSBase()
    {
        if (m_uidMgr) m_uidMgr->TryUnregisterObject(m_uID);
    }

    const CPACSTypeA* CPACSBase::GetParent() const
    {
        return m_parent;
    }

    CPACSTypeA* CPACSBase::GetParent()
    {
        return m_parent;
    }

    CTiglUIDManager& CPACSBase::GetUIDManager()
    {
        return *m_uidMgr;
    }

    const CTiglUIDManager& CPACSBase::GetUIDManager() const
    {
        return *m_uidMgr;
    }

    void CPACSBase::ReadCPACS(const TixiDocumentHandle& tixiHandle, const std::string& xpath)
    {
        // read attribute uID
        if (tixi::TixiCheckAttribute(tixiHandle, xpath, "uID")) {
            m_uID = tixi::TixiGetAttribute<std::string>(tixiHandle, xpath, "uID");
            if (m_uID.empty()) {
                LOG(WARNING) << "Required attribute uID is empty at xpath " << xpath;
            }
        }
        else {
            LOG(ERROR) << "Required attribute uID is missing at xpath " << xpath;
        }

        if (m_uidMgr && !m_uID.empty()) m_uidMgr->RegisterObject(m_uID, *this);
    }

    void CPACSBase::WriteCPACS(const TixiDocumentHandle& tixiHandle, const std::string& xpath) const
    {
        // write attribute uID
        tixi::TixiSaveAttribute(tixiHandle, xpath, "uID", m_uID);

    }

    const std::string& CPACSBase::GetUID() const
    {
        return m_uID;
    }

    void CPACSBase::SetUID(const std::string& value)
    {
        if (m_uidMgr) {
            m_uidMgr->TryUnregisterObject(m_uID);
            m_uidMgr->RegisterObject(value, *this);
        }
        m_uID = value;
    }

} // namespace generated
} // namespace tigl
// Copyright (c) 2018 RISC Software GmbH
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
#include "CPACSBase.h"
#include "tigl_internal.h"

namespace tigl
{
class CTiglUIDManager;

namespace generated
{
    // This class is used in:
    // CPACSRoot

    // generated from /xsd:schema/xsd:complexType[3]
    class CPACSTypeA
    {
    public:
        TIGL_EXPORT CPACSTypeA(CTiglUIDManager* uidMgr);
        TIGL_EXPORT virtual ~CPACSTypeA();

        TIGL_EXPORT CTiglUIDManager& GetUIDManager();
        TIGL_EXPORT const CTiglUIDManager& GetUIDManager() const;

        TIGL_EXPORT virtual void ReadCPACS(const TixiDocumentHandle& tixiHandle, const std::string& xpath);
        TIGL_EXPORT virtual void WriteCPACS(const TixiDocumentHandle& tixiHandle, const std::string& xpath) const;

        TIGL_EXPORT virtual const CPACSBase& GetData() const;
        TIGL_EXPORT virtual CPACSBase& GetData();

    protected:
        CTiglUIDManager* m_uidMgr;

        CPACSBase m_data;

    private:
        CPACSTypeA(const CPACSTypeA&) = delete;
        CPACSTypeA& operator=(const CPACSTypeA&) = delete;

        CPACSTypeA(CPACSTypeA&&) = delete;
        CPACSTypeA& operator=(CPACSTypeA&&) = delete;
    };
} // namespace generated

// Aliases in tigl namespace
using CCPACSTypeA = generated::CPACSTypeA;
} // namespace tigl
// Copyright (c) 2018 RISC Software GmbH
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

#include "CPACSTypeA.h"
#include "CTiglError.h"
#include "CTiglLogging.h"
#include "CTiglUIDManager.h"
#include "TixiHelper.h"

namespace tigl
{
namespace generated
{
    CPACSTypeA::CPACSTypeA(CTiglUIDManager* uidMgr)
        : m_uidMgr(uidMgr)
        , m_data(this, m_uidMgr)
    {
    }

    CPACSTypeA::~CPACSTypeA()
    {
    }

    CTiglUIDManager& CPACSTypeA::GetUIDManager()
    {
        return *m_uidMgr;
    }

    const CTiglUIDManager& CPACSTypeA::GetUIDManager() const
    {
        return *m_uidMgr;
    }

    void CPACSTypeA::ReadCPACS(const TixiDocumentHandle& tixiHandle, const std::string& xpath)
    {
        // read element data
        if (tixi::TixiCheckElement(tixiHandle, xpath + "/data")) {
            m_data.ReadCPACS(tixiHandle, xpath + "/data");
        }
        else {
            LOG(ERROR) << "Required element data is missing at xpath " << xpath;
        }

    }

    void CPACSTypeA::WriteCPACS(const TixiDocumentHandle& tixiHandle, const std::string& xpath) const
    {
        // write element data
        tixi::TixiCreateElementIfNotExists(tixiHandle, xpath + "/data");
        m_data.WriteCPACS(tixiHandle, xpath + "/data");

    }

    const CPACSBase& CPACSTypeA::GetData() const
    {
        return m_data;
    }

    CPACSBase& CPACSTypeA::GetData()
    {
        return m_data;
    }

} // namespace generated
} // namespace tigl
// Copyright (c) 2018 RISC Software GmbH
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
#include "CPACSBase.h"
#include "tigl_internal.h"

namespace tigl
{
class CTiglUIDManager;

namespace generated
{
    class CPACSTypeB;

    // This class is used in:
    // CPACSTypeB

    // generated from /xsd:schema/xsd:complexType[2]
    class CPACSDerived : public CPACSBase
    {
    public:
        TIGL_EXPORT CPACSDerived(CPACSTypeB* parent, CTiglUIDManager* uidMgr);

        TIGL_EXPORT virtual ~CPACSDerived();

        TIGL_EXPORT CPACSTypeB* GetParent();

        TIGL_EXPORT const CPACSTypeB* GetParent() const;

        TIGL_EXPORT virtual void ReadCPACS(const TixiDocumentHandle& tixiHandle, const std::string& xpath);
        TIGL_EXPORT virtual void WriteCPACS(const TixiDocumentHandle& tixiHandle, const std::string& xpath) const;

        TIGL_EXPORT virtual const boost::optional<std::string>& GetName() const;
        TIGL_EXPORT virtual void SetName(const boost::optional<std::string>& value);

    protected:
        CPACSTypeB* m_parent;

        boost::optional<std::string> m_name;

    private:
        CPACSDerived(const CPACSDerived&) = delete;
        CPACSDerived& operator=(const CPACSDerived&) = delete;

        CPACSDerived(CPACSDerived&&) = delete;
        CPACSDerived& operator=(CPACSDerived&&) = delete;
    };
} // namespace generated

// Aliases in tigl namespace
using CCPACSDerived = generated::CPACSDerived;
using CCPACSTypeB = generated::CPACSTypeB;
} // namespace tigl
// Copyright (c) 2018 RISC Software GmbH
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

#include <cassert>
#include "CPACSDerived.h"
#include "CPACSTypeB.h"
#include "CTiglError.h"
#include "CTiglLogging.h"
#include "CTiglUIDManager.h"
#include "TixiHelper.h"

namespace tigl
{
namespace generated
{
    CPACSDerived::CPACSDerived(CPACSTypeB* parent, CTiglUIDManager* uidMgr)
        : CPACSBase(uidMgr)
    {
        //assert(parent != NULL);
        m_parent = parent;
    }

    CPACSDerived::~CPACSDerived()
    {
    }

    const CPACSTypeB* CPACSDerived::GetParent() const
    {
        return m_parent;
    }

    CPACSTypeB* CPACSDerived::GetParent()
    {
        return m_parent;
    }

    void CPACSDerived::ReadCPACS(const TixiDocumentHandle& tixiHandle, const std::string& xpath)
    {
        // read base
        CPACSBase::ReadCPACS(tixiHandle, xpath);

        // read element name
        if (tixi::TixiCheckElement(tixiHandle, xpath + "/name")) {
            m_name = tixi::TixiGetElement<std::string>(tixiHandle, xpath + "/name");
            if (m_name->empty()) {
                LOG(WARNING) << "Optional element name is present but empty at xpath " << xpath;
            }
        }

    }

    void CPACSDerived::WriteCPACS(const TixiDocumentHandle& tixiHandle, const std::string& xpath) const
    {
        // write base
        CPACSBase::WriteCPACS(tixiHandle, xpath);

        // write element name
        if (m_name) {
            tixi::TixiCreateElementIfNotExists(tixiHandle, xpath + "/name");
            tixi::TixiSaveElement(tixiHandle, xpath + "/name", *m_name);
        }
        else {
            if (tixi::TixiCheckElement(tixiHandle, xpath + "/name")) {
                tixi::TixiRemoveElement(tixiHandle, xpath + "/name");
            }
        }

    }

    const boost::optional<std::string>& CPACSDerived::GetName() const
    {
        return m_name;
    }

    void CPACSDerived::SetName(const boost::optional<std::string>& value)
    {
        m_name = value;
    }

} // namespace generated
} // namespace tigl
// Copyright (c) 2018 RISC Software GmbH
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
#include "CPACSDerived.h"
#include "tigl_internal.h"

namespace tigl
{
class CTiglUIDManager;

namespace generated
{
    // This class is used in:
    // CPACSRoot

    // generated from /xsd:schema/xsd:complexType[4]
    class CPACSTypeB
    {
    public:
        TIGL_EXPORT CPACSTypeB(CTiglUIDManager* uidMgr);
        TIGL_EXPORT virtual ~CPACSTypeB();

        TIGL_EXPORT CTiglUIDManager& GetUIDManager();
        TIGL_EXPORT const CTiglUIDManager& GetUIDManager() const;

        TIGL_EXPORT virtual void ReadCPACS(const TixiDocumentHandle& tixiHandle, const std::string& xpath);
        TIGL_EXPORT virtual void WriteCPACS(const TixiDocumentHandle& tixiHandle, const std::string& xpath) const;

        TIGL_EXPORT virtual const CPACSDerived& GetData() const;
        TIGL_EXPORT virtual CPACSDerived& GetData();

    protected:
        CTiglUIDManager* m_uidMgr;

        CPACSDerived m_data;

    private:
        CPACSTypeB(const CPACSTypeB&) = delete;
        CPACSTypeB& operator=(const CPACSTypeB&) = delete;

        CPACSTypeB(CPACSTypeB&&) = delete;
        CPACSTypeB& operator=(CPACSTypeB&&) = delete;
    };
} // namespace generated

// Aliases in tigl namespace
using CCPACSTypeB = generated::CPACSTypeB;
} // namespace tigl
// Copyright (c) 2018 RISC Software GmbH
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

#include "CPACSTypeB.h"
#include "CTiglError.h"
#include "CTiglLogging.h"
#include "CTiglUIDManager.h"
#include "TixiHelper.h"

namespace tigl
{
namespace generated
{
    CPACSTypeB::CPACSTypeB(CTiglUIDManager* uidMgr)
        : m_uidMgr(uidMgr)
        , m_data(this, m_uidMgr)
    {
    }

    CPACSTypeB::~CPACSTypeB()
    {
    }

    CTiglUIDManager& CPACSTypeB::GetUIDManager()
    {
        return *m_uidMgr;
    }

    const CTiglUIDManager& CPACSTypeB::GetUIDManager() const
    {
        return *m_uidMgr;
    }

    void CPACSTypeB::ReadCPACS(const TixiDocumentHandle& tixiHandle, const std::string& xpath)
    {
        // read element data
        if (tixi::TixiCheckElement(tixiHandle, xpath + "/data")) {
            m_data.ReadCPACS(tixiHandle, xpath + "/data");
        }
        else {
            LOG(ERROR) << "Required element data is missing at xpath " << xpath;
        }

    }

    void CPACSTypeB::WriteCPACS(const TixiDocumentHandle& tixiHandle, const std::string& xpath) const
    {
        // write element data
        tixi::TixiCreateElementIfNotExists(tixiHandle, xpath + "/data");
        m_data.WriteCPACS(tixiHandle, xpath + "/data");

    }

    const CPACSDerived& CPACSTypeB::GetData() const
    {
        return m_data;
    }

    CPACSDerived& CPACSTypeB::GetData()
    {
        return m_data;
    }

} // namespace generated
} // namespace tigl
// Copyright (c) 2018 RISC Software GmbH
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
#include "CPACSTypeA.h"
#include "CPACSTypeB.h"
#include "tigl_internal.h"

namespace tigl
{
class CTiglUIDManager;

namespace generated
{
    // This class is used in:
    // generated from /xsd:schema/xsd:complexType[5]
    class CPACSRoot
    {
    public:
        TIGL_EXPORT CPACSRoot(CTiglUIDManager* uidMgr);
        TIGL_EXPORT virtual ~CPACSRoot();

        TIGL_EXPORT CTiglUIDManager& GetUIDManager();
        TIGL_EXPORT const CTiglUIDManager& GetUIDManager() const;

        TIGL_EXPORT virtual void ReadCPACS(const TixiDocumentHandle& tixiHandle, const std::string& xpath);
        TIGL_EXPORT virtual void WriteCPACS(const TixiDocumentHandle& tixiHandle, const std::string& xpath) const;

        TIGL_EXPORT virtual const CPACSTypeA& GetA() const;
        TIGL_EXPORT virtual CPACSTypeA& GetA();

        TIGL_EXPORT virtual const CPACSTypeB& GetB() const;
        TIGL_EXPORT virtual CPACSTypeB& GetB();

    protected:
        CTiglUIDManager* m_uidMgr;

        CPACSTypeA m_a;
        CPACSTypeB m_b;

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
// Copyright (c) 2018 RISC Software GmbH
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
#include "CTiglUIDManager.h"
#include "TixiHelper.h"

namespace tigl
{
namespace generated
{
    CPACSRoot::CPACSRoot(CTiglUIDManager* uidMgr)
        : m_uidMgr(uidMgr)
        , m_a(m_uidMgr)
        , m_b(m_uidMgr)
    {
    }

    CPACSRoot::~CPACSRoot()
    {
    }

    CTiglUIDManager& CPACSRoot::GetUIDManager()
    {
        return *m_uidMgr;
    }

    const CTiglUIDManager& CPACSRoot::GetUIDManager() const
    {
        return *m_uidMgr;
    }

    void CPACSRoot::ReadCPACS(const TixiDocumentHandle& tixiHandle, const std::string& xpath)
    {
        // read element a
        if (tixi::TixiCheckElement(tixiHandle, xpath + "/a")) {
            m_a.ReadCPACS(tixiHandle, xpath + "/a");
        }
        else {
            LOG(ERROR) << "Required element a is missing at xpath " << xpath;
        }

        // read element b
        if (tixi::TixiCheckElement(tixiHandle, xpath + "/b")) {
            m_b.ReadCPACS(tixiHandle, xpath + "/b");
        }
        else {
            LOG(ERROR) << "Required element b is missing at xpath " << xpath;
        }

    }

    void CPACSRoot::WriteCPACS(const TixiDocumentHandle& tixiHandle, const std::string& xpath) const
    {
        const std::vector<std::string> childElemOrder = { "a", "b" };

        // write element a
        tixi::TixiCreateSequenceElementIfNotExists(tixiHandle, xpath + "/a", childElemOrder);
        m_a.WriteCPACS(tixiHandle, xpath + "/a");

        // write element b
        tixi::TixiCreateSequenceElementIfNotExists(tixiHandle, xpath + "/b", childElemOrder);
        m_b.WriteCPACS(tixiHandle, xpath + "/b");

    }

    const CPACSTypeA& CPACSRoot::GetA() const
    {
        return m_a;
    }

    CPACSTypeA& CPACSRoot::GetA()
    {
        return m_a;
    }

    const CPACSTypeB& CPACSRoot::GetB() const
    {
        return m_b;
    }

    CPACSTypeB& CPACSRoot::GetB()
    {
        return m_b;
    }

} // namespace generated
} // namespace tigl
