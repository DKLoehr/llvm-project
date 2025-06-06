//===-------- MachOObjectFormat.cpp -- MachO format details for ORC -------===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//
//
// ORC-specific MachO object format details.
//
//===----------------------------------------------------------------------===//

#include "llvm/ExecutionEngine/Orc/Shared/MachOObjectFormat.h"

namespace llvm {
namespace orc {

StringRef MachODataCommonSectionName = "__DATA,__common";
StringRef MachODataDataSectionName = "__DATA,__data";
StringRef MachOEHFrameSectionName = "__TEXT,__eh_frame";
StringRef MachOCompactUnwindSectionName = "__LD,__compact_unwind";
StringRef MachOCStringSectionName = "__TEXT,__cstring";
StringRef MachOModInitFuncSectionName = "__DATA,__mod_init_func";
StringRef MachOObjCCatListSectionName = "__DATA,__objc_catlist";
StringRef MachOObjCCatList2SectionName = "__DATA,__objc_catlist2";
StringRef MachOObjCClassListSectionName = "__DATA,__objc_classlist";
StringRef MachOObjCClassNameSectionName = "__TEXT,__objc_classname";
StringRef MachOObjCClassRefsSectionName = "__DATA,__objc_classrefs";
StringRef MachOObjCConstSectionName = "__DATA,__objc_const";
StringRef MachOObjCDataSectionName = "__DATA,__objc_data";
StringRef MachOObjCImageInfoSectionName = "__DATA,__objc_imageinfo";
StringRef MachOObjCMethNameSectionName = "__TEXT,__objc_methname";
StringRef MachOObjCMethTypeSectionName = "__TEXT,__objc_methtype";
StringRef MachOObjCNLCatListSectionName = "__DATA,__objc_nlcatlist";
StringRef MachOObjCNLClassListSectionName = "__DATA,__objc_nlclslist";
StringRef MachOObjCProtoListSectionName = "__DATA,__objc_protolist";
StringRef MachOObjCProtoRefsSectionName = "__DATA,__objc_protorefs";
StringRef MachOObjCSelRefsSectionName = "__DATA,__objc_selrefs";
StringRef MachOSwift5ProtoSectionName = "__TEXT,__swift5_proto";
StringRef MachOSwift5ProtosSectionName = "__TEXT,__swift5_protos";
StringRef MachOSwift5TypesSectionName = "__TEXT,__swift5_types";
StringRef MachOSwift5TypeRefSectionName = "__TEXT,__swift5_typeref";
StringRef MachOSwift5FieldMetadataSectionName = "__TEXT,__swift5_fieldmd";
StringRef MachOSwift5EntrySectionName = "__TEXT,__swift5_entry";
StringRef MachOTextTextSectionName = "__TEXT,__text";
StringRef MachOThreadBSSSectionName = "__DATA,__thread_bss";
StringRef MachOThreadDataSectionName = "__DATA,__thread_data";
StringRef MachOThreadVarsSectionName = "__DATA,__thread_vars";
StringRef MachOUnwindInfoSectionName = "__TEXT,__unwind_info";

StringRef MachOInitSectionNames[22] = {
    MachOModInitFuncSectionName,         MachOObjCCatListSectionName,
    MachOObjCCatList2SectionName,        MachOObjCClassListSectionName,
    MachOObjCClassNameSectionName,       MachOObjCClassRefsSectionName,
    MachOObjCConstSectionName,           MachOObjCDataSectionName,
    MachOObjCImageInfoSectionName,       MachOObjCMethNameSectionName,
    MachOObjCMethTypeSectionName,        MachOObjCNLCatListSectionName,
    MachOObjCNLClassListSectionName,     MachOObjCProtoListSectionName,
    MachOObjCProtoRefsSectionName,       MachOObjCSelRefsSectionName,
    MachOSwift5ProtoSectionName,         MachOSwift5ProtosSectionName,
    MachOSwift5TypesSectionName,         MachOSwift5TypeRefSectionName,
    MachOSwift5FieldMetadataSectionName, MachOSwift5EntrySectionName,
};

bool isMachOInitializerSection(StringRef SegName, StringRef SecName) {
  for (auto &InitSection : MachOInitSectionNames) {
    // Loop below assumes all MachO init sectios have a length-6
    // segment name.
    assert(InitSection[6] == ',' && "Init section seg name has length != 6");
    if (InitSection.starts_with(SegName) && InitSection.substr(7) == SecName)
      return true;
  }
  return false;
}

} // namespace orc
} // namespace llvm
