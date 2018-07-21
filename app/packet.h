#ifndef PACKET_H
#define PACKET_H

#include <QString>
#include "buffer.h"
#include <cstring>
#include <algorithm>

// Types of downlink packets, and functions to make them from loaded buffers.

struct Status {
	// TODO #choose: keep as 2 chars (accurate) or 3 (null terminated, easier
	//               printing)
	char spacecraft_id[2];
	uint32_t time;
	bool time_source;
	char sequence_id[2];
	// TODO #note: to be 8bit reals x 5
	uint8_t obc_temperature;
	uint8_t battery_temperature;
	uint8_t battery_voltage;
	uint8_t battery_current;
	uint8_t charge_current;
	bool antenna_deployment;
	uint16_t data_pending;
	uint8_t reboot_count;
	bool rails_status[6];
	// TODO #note: to be 8bit reals x 4
	uint8_t rx_temperature;
	uint8_t tx_temperature;
	uint8_t pa_temperature;
	uint8_t rx_noisefloor;
};

struct GPS {
	char sequence_id[2];
	uint32_t timestamp;
	float lat;
	float lon;
	float alt;
	// TODO #note: to be 8bit reals x 4
	uint8_t HDOP;
	uint8_t VDOP;
	uint8_t PDOP;
	uint8_t TDOP;
};

struct IMU {
	char sequence_id[2];
	uint32_t timestamp;
	// TODO #note: to be 16bit reals x 5 x 9
	uint16_t Mag_X[5];
	uint16_t Mag_Y[5];
	uint16_t Mag_Z[5];
	uint16_t Gyro_X[5];
	uint16_t Gyro_Y[5];
	uint16_t Gyro_Z[5];
	uint16_t Accel_X[5];
	uint16_t Accel_Y[5];
	uint16_t Accel_Z[5];
};

struct Health {
	char sequence_id[2];
	uint32_t timestamp;
	// TODO #note: to be 8bit reals x 4
	uint8_t obc_temperature;
	uint8_t rx_temperature;
	uint8_t tx_temperature;
	uint8_t pa_temperature;
	uint8_t reboot_count;
	uint16_t data_packets_pending;
	bool antenna_switch;
	// TODO #note: to be 8bit real
	uint8_t rx_noisefloor;
	uint8_t detected_flash_errors;
	uint8_t detected_ram_errors;
	// all floats from here on will be 10bit coming in.
	// TODO #note: to be 10bit reals x 15
	uint16_t battery_voltage;
	uint16_t battery_current;
	uint16_t battery_temperature;
	uint16_t charge_current;
	uint16_t mppt_voltage;
	uint16_t solar_n1_current;
	uint16_t solar_n2_current;
	uint16_t solar_e1_current;
	uint16_t solar_e2_current;
	uint16_t solar_s1_current;
	uint16_t solar_s2_current;
	uint16_t solar_w1_current;
	uint16_t solar_w2_current;
	uint16_t solar_t1_current;
	uint16_t solar_t2_current;
	bool rails_switch_status[6];
	bool rails_overcurrent_status[6];
	uint16_t rail_1_boot_count;
	uint16_t rail_1_overcurrent_count;
	// TODO #note: to be 10bit reals x 2
	uint16_t rail_1_voltage;
	uint16_t rail_1_current;
	uint16_t rail_2_boot_count;
	uint16_t rail_2_overcurrent_count;
	// TODO #note: to be 10bit reals x 2
	uint16_t rail_2_voltage;
	uint16_t rail_2_current;
	uint16_t rail_3_boot_count;
	uint16_t rail_3_overcurrent_count;
	// TODO #note: to be 10bit reals x 2
	uint16_t rail_3_voltage;
	uint16_t rail_3_current;
	uint16_t rail_4_boot_count;
	uint16_t rail_4_overcurrent_count;
	// TODO #note: to be 10bit reals x 2
	uint16_t rail_4_voltage;
	uint16_t rail_4_current;
	uint16_t rail_5_boot_count;
	uint16_t rail_5_overcurrent_count;
	// TODO #note: to be 10bit reals x 2
	uint16_t rail_5_voltage;
	uint16_t rail_5_current;
	uint16_t rail_6_boot_count;
	uint16_t rail_6_overcurrent_count;
	// TODO #note: to be 10bit reals x 6
	uint16_t rail_6_voltage;
	uint16_t rail_6_current;
	uint16_t _3v3_voltage;
	uint16_t _3v3_current;
	uint16_t _5v_voltage;
	uint16_t _5v_current;
};

struct Img {
	char sequence_id[2];
	uint32_t timestamp;
	uint8_t image_id;
	uint16_t fragment_id;
	uint16_t num_fragments;
	char image_data[6]; // TODO: replace once size is finalized
};

struct Config {
	// TODO #incomplete: Missing Conf struct
	char sequence_id[2];
	uint32_t timestamp;
};

union Payload {
	GPS gps;
	IMU imu;
	Health health;
	Img img;
	Config config;
};

enum class PayloadType { Morse=1, GPS=2, IMU=3, Health=4, Img=5, Config=6 };

struct Packet {
	char crc[2];
	char hash[16];
	PayloadType type;
	Status status;
	Payload payload;
	uint32_t downlink_time;
};


void from_buffer (GPS& g, Buffer& b);
void from_buffer (IMU& i, Buffer& b);
void from_buffer (Img& i, Buffer& b);
void from_buffer (Health& h, Buffer& b);
void from_buffer (Status& s, Buffer& b);
void from_buffer (Packet& p, Buffer& b);

#endif // PACKET_H