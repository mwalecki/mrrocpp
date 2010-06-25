// -------------------------------------------------------------------------
//                            task/ecp_t_teach.h dla QNX6
// Definicje struktur danych i metod dla procesow ECP
//
// Modyfikacje:
// 1. metody wirtualne w klasie bazowej sensor - ok. 160
// 2. bonusy do testowania
//
// Ostatnia modyfikacja: 25.06.2003
// autor modyfikacji: tkornuta
// -------------------------------------------------------------------------

#if !defined(_ECP_T_TEACH_H)
#define _ECP_T_TEACH_H

#include "base/ecp/ecp_task.h"
#include "application/teach-dll/ecp_g_teach.h"

namespace mrrocpp {
namespace ecp {
namespace common {
namespace task {

/** @defgroup teach_in_dll Teach in dll
 *  @ingroup application
 *  Single robot application of IRp6 manipulator teaching trajectory with user interface usage and dll usage
 *  @{
 */

class teach: public common::task::task
{
protected:
	generator::teach_tmp* tig;

public:
	// KONSTRUKTORY
	teach(lib::configurator &_config);

	// methods for ECP template to redefine in concrete classes
	void main_task_algorithm(void);

};

/** @} */// end of teach_in

} // namespace task
} // namespace common
} // namespace ecp
} // namespace mrrocpp

#endif
