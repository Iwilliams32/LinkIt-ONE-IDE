#include "vmsys.h"
#include "vmvdorec.h"

typedef VMINT (*vm_get_sym_entry_t)(char* symbol);
extern vm_get_sym_entry_t vm_get_sym_entry;

typedef VMINT (*_vm_vdorec_stop_t)(void);
_vm_vdorec_stop_t _vm_vdorec_stop = NULL;

VMINT vm_vdorec_stop(void)
{
    if (NULL == _vm_vdorec_stop)
        _vm_vdorec_stop = (_vm_vdorec_stop_t)vm_get_sym_entry("vm_vdorec_stop");

    if (NULL != _vm_vdorec_stop)
        return _vm_vdorec_stop();

    return (VMINT )-1;
}