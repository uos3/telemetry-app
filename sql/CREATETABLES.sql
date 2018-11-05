/* TODO: update some of these types as they're finalised, in accordance with modifications to packet.h */
create database if not exists cubesat charset utf8mb4;
use cubesat;

create table if not exists frames (
  frame_id serial primary key,
  frame_bin varbinary(392),
  frame_chksum char(2),
  frame_hash char(16),
  seq_status char(2),
  seq_payload char(2),
  payload_type enum('gps', 'imu', 'health', 'img', 'config'),
  downlink_time timestamp
);

create table if not exists status (
  frame_id bigint unsigned,
  spacecraft_id char(2),
  spacecraft_time timestamp,
  time_source boolean,
  seq_status char(2),

  obc_temperature tinyint,
  battery_temperature tinyint,
  battery_voltage tinyint,
  battery_current tinyint unsigned,
  charge_current tinyint unsigned,
  antenna_deployment boolean,
  data_pending smallint unsigned,
  reboot_count tinyint unsigned,
  rails_1 boolean,
  rails_2 boolean,
  rails_3 boolean,
  rails_4 boolean,
  rails_5 boolean,
  rails_6 boolean,
  rx_temperature tinyint,
  tx_temperature tinyint,
  pa_temperature tinyint,
  rx_noisefloor tinyint unsigned,

  foreign key (frame_id) references frames(frame_id)
);

create table if not exists gps (
  frame_id bigint unsigned,
  seq_payload char(2),
  payload_timestamp timestamp,

  lat decimal(10, 8),
  lon decimal(10, 7),
  alt decimal(10, 5),
  hdop tinyint unsigned,
  vdop tinyint unsigned,
  pdop tinyint unsigned,
  tdop tinyint unsigned,

  foreign key (frame_id) references frames(frame_id)
);

create table if not exists imu (
  frame_id bigint unsigned,
  seq_payload char(2),
  payload_timestamp timestamp,

  mag_x_1 smallint,
  mag_x_2 smallint,
  mag_x_3 smallint,
  mag_x_4 smallint,
  mag_x_5 smallint,
  mag_y_1 smallint,
  mag_y_2 smallint,
  mag_y_3 smallint,
  mag_y_4 smallint,
  mag_y_5 smallint,
  mag_z_1 smallint,
  mag_z_2 smallint,
  mag_z_3 smallint,
  mag_z_4 smallint,
  mag_z_5 smallint,
  gyro_x_1 smallint,
  gyro_x_2 smallint,
  gyro_x_3 smallint,
  gyro_x_4 smallint,
  gyro_x_5 smallint,
  gyro_y_1 smallint,
  gyro_y_2 smallint,
  gyro_y_3 smallint,
  gyro_y_4 smallint,
  gyro_y_5 smallint,
  gyro_z_1 smallint,
  gyro_z_2 smallint,
  gyro_z_3 smallint,
  gyro_z_4 smallint,
  gyro_z_5 smallint,
  accel_x_1 smallint,
  accel_x_2 smallint,
  accel_x_3 smallint,
  accel_x_4 smallint,
  accel_x_5 smallint,
  accel_y_1 smallint,
  accel_y_2 smallint,
  accel_y_3 smallint,
  accel_y_4 smallint,
  accel_y_5 smallint,
  accel_z_1 smallint,
  accel_z_2 smallint,
  accel_z_3 smallint,
  accel_z_4 smallint,
  accel_z_5 smallint,

  foreign key (frame_id) references frames(frame_id)
);

create table if not exists health (
  frame_id bigint unsigned,
  seq_payload char(2),
  payload_timestamp timestamp,

  obc_temperature tinyint,
  rx_temperature tinyint,
  tx_temperature tinyint,
  pa_temperature tinyint,
  reboot_count tinyint unsigned,
  data_packets_pending smallint unsigned,
  antenna_switch boolean,
  rx_noisefloor tinyint unsigned,
  detected_flash_errors tinyint unsigned,
  detected_ram_errors tinyint unsigned,
  battery_voltage smallint,
  battery_current smallint unsigned,
  battery_temperature smallint,
  charge_current smallint unsigned,
  mppt_voltage smallint,
  solar_n1_current smallint unsigned,
  solar_n2_current smallint unsigned,
  solar_e1_current smallint unsigned,
  solar_e2_current smallint unsigned,
  solar_s1_current smallint unsigned,
  solar_s2_current smallint unsigned,
  solar_w1_current smallint unsigned,
  solar_w2_current smallint unsigned,
  solar_t1_current smallint unsigned,
  solar_t2_current smallint unsigned,
  rails_switch_status_1 boolean,
  rails_switch_status_2 boolean,
  rails_switch_status_3 boolean,
  rails_switch_status_4 boolean,
  rails_switch_status_5 boolean,
  rails_switch_status_6 boolean,
  rails_overcurrent_status_1 boolean,
  rails_overcurrent_status_2 boolean,
  rails_overcurrent_status_3 boolean,
  rails_overcurrent_status_4 boolean,
  rails_overcurrent_status_5 boolean,
  rails_overcurrent_status_6 boolean,
  rail_1_boot_count smallint unsigned,
  rail_1_overcurrent_count smallint unsigned,
  rail_1_voltage smallint,
  rail_1_current smallint unsigned,
  rail_2_boot_count smallint unsigned,
  rail_2_overcurrent_count smallint unsigned,
  rail_2_voltage smallint,
  rail_2_current smallint unsigned,
  rail_3_boot_count smallint unsigned,
  rail_3_overcurrent_count smallint unsigned,
  rail_3_voltage smallint,
  rail_3_current smallint unsigned,
  rail_4_boot_count smallint unsigned,
  rail_4_overcurrent_count smallint unsigned,
  rail_4_voltage smallint,
  rail_4_current smallint unsigned,
  rail_5_boot_count smallint unsigned,
  rail_5_overcurrent_count smallint unsigned,
  rail_5_voltage smallint,
  rail_5_current smallint unsigned,
  rail_6_boot_count smallint unsigned,
  rail_6_overcurrent_count smallint unsigned,
  rail_6_voltage smallint,
  rail_6_current smallint unsigned,
  3v3_voltage smallint,
  3v3_current smallint unsigned,
  5v_voltage smallint,
  5v_current smallint unsigned,

  foreign key (frame_id) references frames(frame_id)
);

create table if not exists img (
  frame_id bigint unsigned,
  seq_payload char(2),
  payload_timestamp timestamp,

  image_id tinyint unsigned,
  fragment_id smallint unsigned,
  num_fragments smallint unsigned,

  foreign key (frame_id) references frames(frame_id)
);

/* TODO #finish */
create table if not exists config (
  frame_id bigint unsigned,
  seq_payload char(2),
  payload_timestamp timestamp,

  foreign key (frame_id) references frames(frame_id)
);