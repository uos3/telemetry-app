#ifndef PACKET_H
#define PACKET_H

#include <QString>
#include <buffer.h>
#include <cstring>
#include <algorithm>

// Types
struct Status {
	// TODO: in spec, spacecraft_id is 16bit (2 chars), so this is 3 to
	//       accomodate null terminator.
	char spacecraft_id[3];
	uint32_t time;
	bool time_source;
	char sequence_id[3];
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
	char sequence_id[3];
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
	char sequence_id[3];
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
	char sequence_id[3];
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
	char sequence_id[3];
	uint32_t timestamp;
	uint8_t image_id;
	uint16_t fragment_id;
	uint16_t num_fragments;
	char image_data[6]; // TODO: replace once size is finalized
};

struct Config {
	// TODO #bug: Missing Conf struct
	char sequence_id[3];
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

void from_buffer (GPS& g, Buffer& b) {
	b.setPos(249);
	char* sequence_id = (char*)((uint16_t)b.get(16));
	std::copy(sequence_id, sequence_id+2, g.sequence_id);
	g.sequence_id[2] = '\0';
	g.timestamp = b.get(32);
	g.lat = (float)b.get(32);
	g.lon = (float)b.get(32);
	g.alt = (float)b.get(32);
	g.HDOP = (uint8_t)b.get(8);
	g.VDOP = (uint8_t)b.get(8);
	g.PDOP = (uint8_t)b.get(8);
	g.TDOP = (uint8_t)b.get(8);
}

void from_buffer (IMU& i, Buffer& b) {
	b.setPos(249);
	char* sequence_id = (char*)((uint16_t)b.get(16));
	std::copy(sequence_id, sequence_id+2, i.sequence_id);
	i.sequence_id[2] = '\0';
	i.timestamp = b.get(32);
	uint16_t mag_x[5];
	for (int i=0; i<5; i++) { mag_x[i] = (uint16_t)b.get(16); }
	std::copy(mag_x, mag_x+5, i.Mag_X);
	uint16_t mag_y[5];
	for (int i=0; i<5; i++) { mag_y[i] = (uint16_t)b.get(16); }
	std::copy(mag_y, mag_y+5, i.Mag_Y);
	uint16_t mag_z[5];
	for (int i=0; i<5; i++) { mag_z[i] = (uint16_t)b.get(16); }
	std::copy(mag_z, mag_z+5, i.Mag_Z);
	uint16_t gyro_x[5];
	for (int i=0; i<5; i++) { gyro_x[i] = (uint16_t)b.get(16); }
	std::copy(gyro_x, gyro_x+5, i.Gyro_X);
	uint16_t gyro_y[5];
	for (int i=0; i<5; i++) { gyro_y[i] = (uint16_t)b.get(16); }
	std::copy(gyro_y, gyro_y+5, i.Gyro_Y);
	uint16_t gyro_z[5];
	for (int i=0; i<5; i++) { gyro_z[i] = (uint16_t)b.get(16); }
	std::copy(gyro_z, gyro_z+5, i.Gyro_Z);
	uint16_t accel_x[5];
	for (int i=0; i<5; i++) { accel_x[i] = (uint16_t)b.get(16); }
	std::copy(accel_x, accel_x+5, i.Accel_X);
	uint16_t accel_y[5];
	for (int i=0; i<5; i++) { accel_y[i] = (uint16_t)b.get(16); }
	std::copy(accel_y, accel_y+5, i.Accel_Y);
	uint16_t accel_z[5];
	for (int i=0; i<5; i++) { accel_z[i] = (uint16_t)b.get(16); }
	std::copy(accel_z, accel_z+5, i.Accel_Z);
}

void from_buffer (Img& i, Buffer& b) {
	b.setPos(249);
	char* sequence_id = (char*)((uint16_t)b.get(16));
	std::copy(sequence_id, sequence_id+2, i.sequence_id);
	i.sequence_id[2] = '\0';
	i.timestamp = b.get(32);
	i.image_id = (uint8_t)b.get(8);
	i.fragment_id = (uint16_t)b.get(16);
	i.num_fragments = (uint16_t)b.get(16);
	char image_data[6] = { 'i', 'm', 'a', 'g', 'e', '\0' };
	std::copy(image_data, image_data+6, i.image_data);
}

void from_buffer (Health& h, Buffer& b) {
	b.setPos(249);
	char* sequence_id = (char*)((uint16_t)b.get(16));
	std::copy(sequence_id, sequence_id+2, h.sequence_id);
	h.sequence_id[2] = '\0';
	h.timestamp = b.get(32);
	h.obc_temperature = (uint8_t)b.get(8);
	h.rx_temperature = (uint8_t)b.get(8);
	h.tx_temperature = (uint8_t)b.get(8);
	h.pa_temperature = (uint8_t)b.get(8);
	h.reboot_count = (uint8_t)b.get(8);
	h.data_packets_pending = (uint16_t)b.get(16);
	h.antenna_switch = (bool)b.get(1);
	h.rx_noisefloor = (uint8_t)b.get(8);
	h.detected_flash_errors = (uint8_t)b.get(4);
	h.detected_ram_errors = (uint8_t)b.get(4);
	h.battery_voltage = (uint16_t)b.get(10);
	h.battery_current = (uint16_t)b.get(10);
	h.battery_temperature = (uint16_t)b.get(10);
	h.charge_current = (uint16_t)b.get(10);
	h.mppt_voltage = (uint16_t)b.get(10);
	h.solar_n1_current = (uint16_t)b.get(10);
	h.solar_n2_current = (uint16_t)b.get(10);
	h.solar_e1_current = (uint16_t)b.get(10);
	h.solar_e2_current = (uint16_t)b.get(10);
	h.solar_s1_current = (uint16_t)b.get(10);
	h.solar_s2_current = (uint16_t)b.get(10);
	h.solar_w1_current = (uint16_t)b.get(10);
	h.solar_w2_current = (uint16_t)b.get(10);
	h.solar_t1_current = (uint16_t)b.get(10);
	h.solar_t2_current = (uint16_t)b.get(10);
	bool rails_switch_status[6] = {
	    (bool)b.get(1), (bool)b.get(1), (bool)b.get(1),
	    (bool)b.get(1), (bool)b.get(1), (bool)b.get(1)
	};
	std::copy(rails_switch_status, rails_switch_status+6, h.rails_switch_status);
	bool rails_overcurrent_status[6] = {
	    (bool)b.get(1), (bool)b.get(1), (bool)b.get(1),
	    (bool)b.get(1), (bool)b.get(1), (bool)b.get(1)
	};
	std::copy(rails_overcurrent_status, rails_overcurrent_status+6, h.rails_overcurrent_status);
	h.rail_1_boot_count = (uint16_t)b.get(16);
	h.rail_1_overcurrent_count = (uint16_t)b.get(16);
	h.rail_1_voltage = (uint16_t)b.get(10);
	h.rail_1_current = (uint16_t)b.get(10);
	h.rail_2_boot_count = (uint16_t)b.get(16);
	h.rail_2_overcurrent_count = (uint16_t)b.get(16);
	h.rail_2_voltage = (uint16_t)b.get(10);
	h.rail_2_current = (uint16_t)b.get(10);
	h.rail_3_boot_count = (uint16_t)b.get(16);
	h.rail_3_overcurrent_count = (uint16_t)b.get(16);
	h.rail_3_voltage = (uint16_t)b.get(10);
	h.rail_3_current = (uint16_t)b.get(10);
	h.rail_4_boot_count = (uint16_t)b.get(16);
	h.rail_4_overcurrent_count = (uint16_t)b.get(16);
	h.rail_4_voltage = (uint16_t)b.get(10);
	h.rail_4_current = (uint16_t)b.get(10);
	h.rail_5_boot_count = (uint16_t)b.get(16);
	h.rail_5_overcurrent_count = (uint16_t)b.get(16);
	h.rail_5_voltage = (uint16_t)b.get(10);
	h.rail_5_current = (uint16_t)b.get(10);
	h.rail_6_boot_count = (uint16_t)b.get(16);
	h.rail_6_overcurrent_count = (uint16_t)b.get(16);
	h.rail_6_voltage = (uint16_t)b.get(10);
	h.rail_6_current = (uint16_t)b.get(10);
	h._3v3_voltage = (uint16_t)b.get(10);
	h._3v3_current = (uint16_t)b.get(10);
	h._5v_voltage = (uint16_t)b.get(10);
	h._5v_current = (uint16_t)b.get(10);
}

void from_buffer (Status& s, Buffer& b) {
	// TODO #bug: will the pointery stuff get reclaimed after the function?
	b.setPos(80);
	char* spacecraft_id = (char*)((uint16_t)b.get(16));
	std::copy(spacecraft_id, spacecraft_id+2, s.spacecraft_id);
	s.spacecraft_id[2] = '\0';
	s.time = b.get(32);
	s.time_source = (bool)b.get(2);
	char* sequence_id = (char*)((uint16_t)b.get(16));
	std::copy(sequence_id, sequence_id+2, s.sequence_id);
	s.sequence_id[2] = '\0';
	s.obc_temperature = (uint8_t)b.get(8);
	s.battery_temperature = (uint8_t)b.get(8);
	s.battery_voltage = (uint8_t)b.get(8);
	s.battery_current = (uint8_t)b.get(8);
	s.charge_current = (uint8_t)b.get(8);
	s.antenna_deployment = (bool)b.get(1);
	s.data_pending = (uint16_t)b.get(16);
	s.reboot_count = (uint8_t)b.get(8);
	bool rails_status[6] = {
	    (bool)b.get(1), (bool)b.get(1), (bool)b.get(1),
	    (bool)b.get(1), (bool)b.get(1), (bool)b.get(1)
	};
	std::copy(rails_status, rails_status+6, s.rails_status);
	s.rx_temperature = (uint8_t)b.get(8);
	s.tx_temperature = (uint8_t)b.get(8);
	s.pa_temperature = (uint8_t)b.get(8);
	s.rx_noisefloor = (uint8_t)b.get(8);
}

void from_buffer (Packet& p, Buffer& b) {
	b.setPos(64);
	p.type = static_cast<PayloadType>(b.get(16));
	from_buffer(p.status, b);
	switch (p.type) {
		case PayloadType::GPS :
			from_buffer(p.payload.gps, b);
			break;
		case PayloadType::IMU :
			from_buffer(p.payload.imu, b);
			break;
		case PayloadType::Health :
			from_buffer(p.payload.health, b);
			break;
		case PayloadType::Img :
			from_buffer(p.payload.img, b);
			break;
		case PayloadType::Config :
			// TODO #bug: Needs finishing
			break;
		default:
			throw std::runtime_error("invalid payload type while parsing packet.");
			break;
	}
	// TODO #verify: assumes crc & hash occupy last 144 bits of packet (as
	//               opposed to the 144 bits that come after the payload).
	strncpy(p.hash, b.getBuf()+144, 16);
	strncpy(p.crc, b.getBuf()+160, 2);
}


#endif // PACKET_H
