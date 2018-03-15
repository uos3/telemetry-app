#ifndef PACKET_H
#define PACKET_H

#include <QString>

// Types
struct Status {
	// TODO: in spec, spacecraft_id is 16bit (2 chars), so this is 3 to
	//       accomodate null terminator.
	char spacecraft_id[3];
	uint32_t time;
	bool time_source;
	char sequence_id[3];
	// TODO - NOTE: according to the spec, these are 8bit reals (at least from
	//              the cubesat) -- will need to convert.
	float obc_temperature;
	float battery_temperature;
	float battery_voltage;
	float battery_current;
	float charge_current;
	bool antenna_deployment;
	uint16_t data_pending;
	uint8_t reboot_count;
	bool rails_status[6];
	float rx_temperature;
	float tx_temperature;
	float pa_temperature;
	float rx_noisefloor;
};

struct GPS {
	char sequence_id[3];
	uint32_t timestamp;
	float lat;
	float lon;
	float alt;
	float HDOP;
	float VDOP;
	float PDOP;
	float TDOP;
};

struct IMU {
	char sequence_id[3];
	uint32_t timestamp;
	// TODO: are likely reals, not ints
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

struct Img {
	char sequence_id[3];
	uint32_t timestamp;
	uint8_t image_id;
	uint16_t fragment_id;
	uint16_t num_fragments;
	// TODO: replace once size is finalized
	char image_data[6];
};

struct Health {
	// TODO - actual types
	char sequence_id[3];
	uint32_t timestamp;
	float obc_temperature;
	float rx_temperature;
	float tx_temperature;
	float pa_temperature;
	uint8_t reboot_count;
	uint16_t data_packets_pending;
	bool antenna_switch;
	float rx_noisefloor;
	unsigned int detected_flash_errors : 4; // aka. 4bit int
	unsigned int detected_ram_errors : 4;
	// all floats from here on will be 10bit coming in.
	float battery_voltage;
	float battery_current;
	float battery_temperature;
	float charge_current;
	float mppt_voltage;
	float solar_n1_current;
	float solar_n2_current;
	float solar_e1_current;
	float solar_e2_current;
	float solar_s1_current;
	float solar_s2_current;
	float solar_w1_current;
	float solar_w2_current;
	float solar_t1_current;
	float solar_t2_current;
	bool rails_switch_status[6];
	bool rails_overcurrent_status[6];
	uint16_t rail_1_boot_count;
	uint16_t rail_1_overcurrent_count;
	float rail_1_voltage;
	float rail_1_current;
	uint16_t rail_2_boot_count;
	uint16_t rail_2_overcurrent_count;
	float rail_2_voltage;
	float rail_2_current;
	uint16_t rail_3_boot_count;
	uint16_t rail_3_overcurrent_count;
	float rail_3_voltage;
	float rail_3_current;
	uint16_t rail_4_boot_count;
	uint16_t rail_4_overcurrent_count;
	float rail_4_voltage;
	float rail_4_current;
	uint16_t rail_5_boot_count;
	uint16_t rail_5_overcurrent_count;
	float rail_5_voltage;
	float rail_5_current;
	uint16_t rail_6_boot_count;
	uint16_t rail_6_overcurrent_count;
	float rail_6_voltage;
	float rail_6_current;
	float _3v3_voltage;
	float _3v3_current;
	float _5v_voltage;
	float _5v_current;
};

//struct ts_dt {
//	char member[6];
//};

union Payload {
	GPS gps;
	IMU imu;
	Img img;
	Health health;
//	ts_dt td;
};

enum class PayloadType { Morse=1, GPS=2, IMU=3, Health=4, Img=5, Conf=6 };

struct Packet {
	char crc[16];
	char hash[16];
	PayloadType type;
	Status status;
	Payload payload;
	uint32_t downlink_time;
};

#endif // PACKET_H