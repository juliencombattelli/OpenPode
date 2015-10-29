/*
 * Servo.h
 *
 *  Created on: 29 sept. 2015
 *      Author: Julien
 */

#ifndef SERVO_H_
#define SERVO_H_

enum Side_enum
{
	side_left,
	side_right
};

enum Paw_position_enum
{
	position_front,
	position_middle,
	position_back
};

enum Servo_position_enum
{
	position_tibia,
	position_femur,
	position_coxa
};

class Servo
{
public:

	Servo(Side_enum side, Paw_position_enum paw_position, Servo_position_enum servo_position);

	static const int min_ratio = 205;
	static const int max_ratio = 441;
	static constexpr double excursion_deg = 120.0;
	static constexpr double resolution = double(max_ratio-min_ratio)/excursion_deg;

	int get_offset() const;

public:

	Side_enum m_side;
	Paw_position_enum m_paw_position;
	Servo_position_enum m_position;

	int m_offset;
};



#endif /* SERVO_H_ */
