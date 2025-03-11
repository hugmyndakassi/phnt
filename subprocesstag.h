/*
 * Subprocess tag information
 *
 * This file is part of System Informer.
 */

#ifndef _SUBPROCESSTAG_H
#define _SUBPROCESSTAG_H

typedef enum _TAG_INFO_LEVEL
{
    eTagInfoLevelNameFromTag = 1, // TAG_INFO_NAME_FROM_TAG
    eTagInfoLevelNamesReferencingModule, // TAG_INFO_NAMES_REFERENCING_MODULE
    eTagInfoLevelNameTagMapping, // TAG_INFO_NAME_TAG_MAPPING
    eTagInfoLevelMax
} TAG_INFO_LEVEL;

typedef enum _TAG_TYPE
{
    eTagTypeService = 1,
    eTagTypeMax
} TAG_TYPE;

typedef struct _TAG_INFO_NAME_FROM_TAG_IN_PARAMS
{
    ULONG ProcessId;
    ULONG ServiceTag;
} TAG_INFO_NAME_FROM_TAG_IN_PARAMS, *PTAG_INFO_NAME_FROM_TAG_IN_PARAMS;

typedef struct _TAG_INFO_NAME_FROM_TAG_OUT_PARAMS
{
    ULONG TagType;
    PCWSTR Name;
} TAG_INFO_NAME_FROM_TAG_OUT_PARAMS, *PTAG_INFO_NAME_FROM_TAG_OUT_PARAMS;

typedef struct _TAG_INFO_NAME_FROM_TAG
{
    TAG_INFO_NAME_FROM_TAG_IN_PARAMS InParams;
    TAG_INFO_NAME_FROM_TAG_OUT_PARAMS OutParams;
} TAG_INFO_NAME_FROM_TAG, *PTAG_INFO_NAME_FROM_TAG;

typedef struct _TAG_INFO_NAMES_REFERENCING_MODULE_IN_PARAMS
{
    ULONG ProcessId;
    PCWSTR ModuleName;
} TAG_INFO_NAMES_REFERENCING_MODULE_IN_PARAMS, *PTAG_INFO_NAMES_REFERENCING_MODULE_IN_PARAMS;

typedef struct _TAG_INFO_NAMES_REFERENCING_MODULE_OUT_PARAMS
{
    ULONG TagType;
    PCWSTR Names;
} TAG_INFO_NAMES_REFERENCING_MODULE_OUT_PARAMS, *PTAG_INFO_NAMES_REFERENCING_MODULE_OUT_PARAMS;

typedef struct _TAG_INFO_NAMES_REFERENCING_MODULE
{
    TAG_INFO_NAMES_REFERENCING_MODULE_IN_PARAMS InParams;
    TAG_INFO_NAMES_REFERENCING_MODULE_OUT_PARAMS OutParams;
} TAG_INFO_NAMES_REFERENCING_MODULE, *PTAG_INFO_NAMES_REFERENCING_MODULE;

typedef struct _TAG_INFO_NAME_TAG_MAPPING_IN_PARAMS
{
    ULONG ProcessId;
} TAG_INFO_NAME_TAG_MAPPING_IN_PARAMS, *PTAG_INFO_NAME_TAG_MAPPING_IN_PARAMS;

typedef struct _TAG_INFO_NAME_TAG_MAPPING_ELEMENT
{
    ULONG TagType;
    ULONG Tag;
    PCWSTR Name;
    PCWSTR GroupName;
} TAG_INFO_NAME_TAG_MAPPING_ELEMENT, *PTAG_INFO_NAME_TAG_MAPPING_ELEMENT;

typedef struct _TAG_INFO_NAME_TAG_MAPPING_OUT_PARAMS
{
    ULONG Count;
    PTAG_INFO_NAME_TAG_MAPPING_ELEMENT NameTagMappingElements;
} TAG_INFO_NAME_TAG_MAPPING_OUT_PARAMS, *PTAG_INFO_NAME_TAG_MAPPING_OUT_PARAMS;

typedef struct _TAG_INFO_NAME_TAG_MAPPING
{
    TAG_INFO_NAME_TAG_MAPPING_IN_PARAMS InParams;
    PTAG_INFO_NAME_TAG_MAPPING_OUT_PARAMS pOutParams;
} TAG_INFO_NAME_TAG_MAPPING, *PTAG_INFO_NAME_TAG_MAPPING;

_Must_inspect_result_
NTSYSAPI
ULONG
NTAPI
I_QueryTagInformation(
    _In_opt_ PCWSTR MachineName,
    _In_ TAG_INFO_LEVEL InfoLevel,
    _Inout_ PVOID TagInfo
    );

typedef _Function_class_(QUERY_TAG_INFORMATION)
ULONG NTAPI QUERY_TAG_INFORMATION(
    _In_opt_ PCWSTR MachineName,
    _In_ TAG_INFO_LEVEL InfoLevel,
    _Inout_ PVOID TagInfo
    );
typedef QUERY_TAG_INFORMATION *PQUERY_TAG_INFORMATION;

#endif
