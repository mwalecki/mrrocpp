// -------------------------------------------------------------------------
//                            robot.h
// Definicje struktur danych i metod do komunikacji UI z EDP
//
// Ostatnia modyfikacja: 16.04.98
// -------------------------------------------------------------------------

#ifndef _UI_ECP_R_COMMON_H
#define _UI_ECP_R_COMMON_H

#include "../ui.h"
#include "../ui_robot.h"
// Konfigurator.
#include "base/lib/configurator.h"
#include "base/lib/mrmath/mrmath.h"

#include "base/ecp/ecp_robot.h"

namespace mrrocpp {
namespace ui {
namespace common {
class UiRobot;

}

namespace common012 {

// ---------------------------------------------------------------
class EcpRobot
{
protected:

	// Klasa do obslugi robotow irp6 z poziomu UI

	// Dopuszczalne przyrosty polozenia w pojedynczym kroku [2ms] przy ruchach
	// recznych dla roznych wspolrzednych
	double MOTOR_STEP[lib::MAX_SERVOS_NR]; // Przyrost kata obrotu walu silnika [rad]
	double JOINT_STEP[lib::MAX_SERVOS_NR]; // Przyrost kata obrotu w przegubie obrotowym [rad]
	double END_EFFECTOR_STEP[lib::MAX_SERVOS_NR]; // Przyrost wspolrzednej polozenia koncowki [mm]

	double desired_position[lib::MAX_SERVOS_NR]; // polozenie zadane
	double current_position[lib::MAX_SERVOS_NR]; // polozenie aktualne

public:
	common::UiRobot& ui_robot;
	ecp::common::robot::ecp_robot *ecp;

	// ecp_buffer ui_edp_package; // by Y
	EcpRobot(common::UiRobot& _ui_robot); // Konstruktor

	void init();

	void move_motors(const double final_position[lib::MAX_SERVOS_NR]);
	void move_joints(const double final_position[lib::MAX_SERVOS_NR]);

	virtual ~EcpRobot();

	virtual void execute_motion(void);
	// virtual void set_edp_master_pid ( pid_t edppid ) {EDP_Pid = edppid;};
	// Przekazanie identyfikatora procesu EDP
	// virtual void synchronise ( void ); // Zlecenie synchronizacji robota
	// virtual bool is_synchronised( void ) { return synchronised;};

	virtual void set_desired_position(const double des_position[lib::MAX_SERVOS_NR]);
	// Przepisanie polozen zadanych
	// do tablicy desired_position[]
	virtual void get_current_position(double c_position[lib::MAX_SERVOS_NR]); // Pobranie aktualnych polozen

	// by Y - do odczytu stanu poczatkowego robota
	void get_controller_state(lib::controller_state_t & robot_controller_initial_state_l);

	// Zlecenie ruchu
	void set_kinematic(uint8_t kinematic_model_no);
	void set_servo_algorithm(uint8_t algorithm_no[lib::MAX_SERVOS_NR], uint8_t parameters_no[lib::MAX_SERVOS_NR]);

	// Odczyt polozenia
	void read_motors(double current_position[lib::MAX_SERVOS_NR]);
	void read_joints(double current_position[lib::MAX_SERVOS_NR]);
	void get_kinematic(uint8_t* kinematic_model_no);
	void get_servo_algorithm(uint8_t algorithm_no[lib::MAX_SERVOS_NR], uint8_t parameters_no[lib::MAX_SERVOS_NR]);

	// Zlecenie ruchu
	void move_xyz_euler_zyz(const double final_position[7]);
	void move_xyz_angle_axis(const double final_position[7]);
	void move_xyz_angle_axis_relative(const double position_increment[7]);
	void set_tool_xyz_angle_axis(const lib::Xyz_Angle_Axis_vector &tool_vector);
	void set_tool_xyz_euler_zyz(const lib::Xyz_Euler_Zyz_vector &tool_vector);

	// Odczyt polozenia
	void read_xyz_euler_zyz(double current_position[7]);
	void read_xyz_angle_axis(double current_position[7]);
	void read_tool_xyz_angle_axis(lib::Xyz_Angle_Axis_vector & tool_vector);
	void read_tool_xyz_euler_zyz(lib::Xyz_Euler_Zyz_vector &tool_vector);

};

}
} //namespace ui
} //namespace mrrocpp
#endif
