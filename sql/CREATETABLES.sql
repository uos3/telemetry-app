/* TODO: update some of these types as they're finalised, in accordance with modifications to packet.h */

create table if not exists frames (
  frame_id int not null auto_increment primary key,
  frame_bin varbinary(392),
  frame_chksum char(2),
  frame_hash char(16),
  seq_status char(2),
  seq_payload char(2),
  payload_type enum('gps', 'imu', 'health', 'img', 'config'),
  downlink_time timestamp
);

create table if not exists status (
  frame_id int,
  spacecraft_id char(2),
  spacecraft_time timestamp,
  time_source boolean,
  seq_status char(2),

  obc_temperature tinyint,
  battery_temperature tinyint,
  battery_voltage tinyint,
  battery_current tinyint,
  charge_current tinyint,
  antenna_deployment boolean,
  data_pending smallint,
  reboot_count tinyint,
  rails_1 boolean,
  rails_2 boolean,
  rails_3 boolean,
  rails_4 boolean,
  rails_5 boolean,
  rails_6 boolean,
  rx_temperature tinyint,
  tx_temperature tinyint,
  pa_temperature tinyint,
  rx_noisefloor tinyint,

  foreign key (frame_id) references frames(frame_id)
);

create table if not exists gps (
  frame_id int,
  seq_payload char(2),
  payload_timestamp timestamp,

  lat decimal(10, 8),
  lon decimal(10, 7),
  alt decimal(10, 5),
  hdop tinyint,
  vdop tinyint,
  pdop tinyint,
  tdop tinyint,

  foreign key (frame_id) references frames(frame_id)
);

create table if not exists imu (
  frame_id int,
  seq_payload char(2),
  payload_timestamp timestamp,

  mag_x_1 smallint,
  mag_x_2 smallint,
  mag_x_3 smallint,
  mag_x_4 smallint,
  mag_x_5 smallint,
  gyro_x_1 smallint,
  gyro_x_2 smallint,
  gyro_x_3 smallint,
  gyro_x_4 smallint,
  gyro_x_5 smallint,
  accel_x_1 smallint,
  accel_x_2 smallint,
  accel_x_3 smallint,
  accel_x_4 smallint,
  accel_x_5 smallint,

  foreign key (frame_id) references frames(frame_id)
);

create table if not exists health (
  frame_id int,
  seq_payload char(2),
  payload_timestamp timestamp,

  obc_temperature tinyint,
  rx_temperature tinyint,
  tx_temperature tinyint,
  pa_temperature tinyint,
  reboot_count tinyint,
  data_packets_pending smallint,
  antenna_switch boolean,
  rx_noisefloor tinyint,
  detected_flash_errors tinyint,
  detected_ram_errors tinyint,
  battery_voltage smallint,
  battery_current smallint,
  battery_temperature smallint,
  charge_current smallint,
  mppt_voltage smallint,
  solar_n1_current smallint,
  solar_n2_current smallint,
  solar_e1_current smallint,
  solar_e2_current smallint,
  solar_s1_current smallint,
  solar_s2_current smallint,
  solar_w1_current smallint,
  solar_w2_current smallint,
  solar_t1_current smallint,
  solar_t2_current smallint,
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
  rail_1_boot_count smallint,
  rail_1_overcurrent_count smallint,
  rail_1_voltage smallint,
  rail_1_current smallint,
  rail_2_boot_count smallint,
  rail_2_overcurrent_count smallint,
  rail_2_voltage smallint,
  rail_2_current smallint,
  rail_3_boot_count smallint,
  rail_3_overcurrent_count smallint,
  rail_3_voltage smallint,
  rail_3_current smallint,
  rail_4_boot_count smallint,
  rail_4_overcurrent_count smallint,
  rail_4_voltage smallint,
  rail_4_current smallint,
  rail_5_boot_count smallint,
  rail_5_overcurrent_count smallint,
  rail_5_voltage smallint,
  rail_5_current smallint,
  rail_6_boot_count smallint,
  rail_6_overcurrent_count smallint,
  rail_6_voltage smallint,
  rail_6_current smallint,
  _3v3_voltage smallint,
  _3v3_current smallint,
  _5v_voltage smallint,
  _5v_current smallint,

  foreign key (frame_id) references frames(frame_id)
);

create table if not exists img (
  frame_id int,
  seq_payload char(2),
  payload_timestamp timestamp,

  image_id tinyint,
  fragment_id smallint,
  num_fragments smallint,

  foreign key (frame_id) references frames(frame_id)
);

/* TODO #finish */
create table if not exists config (
  frame_id int,
  seq_payload char(2),
  payload_timestamp timestamp,

  foreign key (frame_id) references frames(frame_id)
);