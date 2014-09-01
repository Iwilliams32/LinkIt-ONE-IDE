#include "vmsys.h"
#include "vmmm.h"

typedef VMINT (*vm_get_sym_entry_t)(char* symbol);
extern vm_get_sym_entry_t vm_get_sym_entry;

typedef VMINT (*_vm_record_stop_t)(void);
_vm_record_stop_t _vm_record_stop = NULL;

VMINT vm_record_stop(void)
{
    if (NULL == _vm_record_stop)
        _vm_record_stop = (_vm_record_stop_t)vm_get_sym_entry("vm_record_stop");

    if (NULL != _vm_record_stop)
        return _vm_record_stop();

    return (VMINT )-1;
}