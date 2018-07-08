#include "packet.h"

/* Overloaded from_buffer functions that extract data from the buffer into the
corresponding structs */

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
		case PayloadType::GPS:
			from_buffer(p.payload.gps, b);
			break;
		case PayloadType::IMU:
			from_buffer(p.payload.imu, b);
			break;
		case PayloadType::Health:
			from_buffer(p.payload.health, b);
			break;
		case PayloadType::Img:
			from_buffer(p.payload.img, b);
			break;
		case PayloadType::Config:
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