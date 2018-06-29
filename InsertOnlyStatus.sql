/* CREATE TABLE */
CREATE TABLE IF NOT EXISTS STATUS(
  SCID INT(11),
  time VARCHAR(100),
  time_source DECIMAL(10, 2),
  beacon_id DECIMAL(10, 2),
  obc_temp DECIMAL(10, 2),
  bat_temp DECIMAL(10, 2),
  bat_volt DECIMAL(10, 2),
  bat_current DECIMAL(10, 2),
  charge_current DECIMAL(10, 2),
  ant_dep DECIMAL(10, 2),
  ops_mode DECIMAL(10, 2),
  data_pend DECIMAL(10, 2),
  reboot_cnt DECIMAL(10, 2),
  rail_stat DECIMAL(10, 2),
  rx_temp DECIMAL(10, 2),
  tx_temp DECIMAL(10, 2),
  pa_temp DECIMAL(10, 2),
  rx_floor DECIMAL(10, 2)
);
/* INSERT QUERY */
INSERT INTO STATUS(
  SCID, time, time_source, beacon_id,
  obc_temp, bat_temp, bat_volt, bat_current,
  charge_current, ant_dep, ops_mode,
  data_pend, reboot_cnt, rail_stat,
  rx_temp, tx_temp, pa_temp, rx_floor
)
VALUES
  (
    16962, '01/01/2020 10:00', 1, 7,-50,
    -51, 11, 0, 10, 0, 10, 86, 0, 3, 50, 51,
    50, 24
  );
/* INSERT QUERY */
INSERT INTO STATUS(
  SCID, time, time_source, beacon_id,
  obc_temp, bat_temp, bat_volt, bat_current,
  charge_current, ant_dep, ops_mode,
  data_pend, reboot_cnt, rail_stat,
  rx_temp, tx_temp, pa_temp, rx_floor
)
VALUES
  (
    16962, '02/01/2020 10:00', 1, 8,-47,
    -47, 11, 4, 14, 0, 10, 90, 0, 1, 47, 47,
    50, 61
  );
/* INSERT QUERY */
INSERT INTO STATUS(
  SCID, time, time_source, beacon_id,
  obc_temp, bat_temp, bat_volt, bat_current,
  charge_current, ant_dep, ops_mode,
  data_pend, reboot_cnt, rail_stat,
  rx_temp, tx_temp, pa_temp, rx_floor
)
VALUES
  (
    16962, '03/01/2020 10:00', 1, 9,-44,
    -45, 10, 8, 18, 0, 10, 67, 0, 4, 44, 45,
    50, 55
  );
/* INSERT QUERY */
INSERT INTO STATUS(
  SCID, time, time_source, beacon_id,
  obc_temp, bat_temp, bat_volt, bat_current,
  charge_current, ant_dep, ops_mode,
  data_pend, reboot_cnt, rail_stat,
  rx_temp, tx_temp, pa_temp, rx_floor
)
VALUES
  (
    16962, '04/01/2020 10:00', 1, 10,-41,
    -42, 10, 12, 22, 0, 10, 12, 0, 5, 41, 42,
    50, 22
  );
/* INSERT QUERY */
INSERT INTO STATUS(
  SCID, time, time_source, beacon_id,
  obc_temp, bat_temp, bat_volt, bat_current,
  charge_current, ant_dep, ops_mode,
  data_pend, reboot_cnt, rail_stat,
  rx_temp, tx_temp, pa_temp, rx_floor
)
VALUES
  (
    16962, '05/01/2020 10:00', 1, 11,-38,
    -39, 10, 16, 26, 0, 10, 87, 0, 1, 38, 39,
    50, 41
  );
/* INSERT QUERY */
INSERT INTO STATUS(
  SCID, time, time_source, beacon_id,
  obc_temp, bat_temp, bat_volt, bat_current,
  charge_current, ant_dep, ops_mode,
  data_pend, reboot_cnt, rail_stat,
  rx_temp, tx_temp, pa_temp, rx_floor
)
VALUES
  (
    16962, '06/01/2020 10:00', 1, 15,-36,
    -36, 9, 20, 30, 0, 10, 108, 0, 1, 36, 36,
    50, 67
  );
/* INSERT QUERY */
INSERT INTO STATUS(
  SCID, time, time_source, beacon_id,
  obc_temp, bat_temp, bat_volt, bat_current,
  charge_current, ant_dep, ops_mode,
  data_pend, reboot_cnt, rail_stat,
  rx_temp, tx_temp, pa_temp, rx_floor
)
VALUES
  (
    16962, '07/01/2020 10:00', 1, 16,-33,
    -33, 9, 24, 34, 0, 10, 127, 0, 0, 33, 33,
    50, 33
  );
/* INSERT QUERY */
INSERT INTO STATUS(
  SCID, time, time_source, beacon_id,
  obc_temp, bat_temp, bat_volt, bat_current,
  charge_current, ant_dep, ops_mode,
  data_pend, reboot_cnt, rail_stat,
  rx_temp, tx_temp, pa_temp, rx_floor
)
VALUES
  (
    16962, '08/01/2020 10:00', 1, 17,-30,
    -31, 9, 28, 38, 0, 10, 14, 0, 2, 30, 31,
    50, 1
  );
/* INSERT QUERY */
INSERT INTO STATUS(
  SCID, time, time_source, beacon_id,
  obc_temp, bat_temp, bat_volt, bat_current,
  charge_current, ant_dep, ops_mode,
  data_pend, reboot_cnt, rail_stat,
  rx_temp, tx_temp, pa_temp, rx_floor
)
VALUES
  (
    16962, '09/01/2020 10:00', 1, 18,-28,
    -28, 9, 32, 42, 0, 10, 61, 0, 4, 28, 28,
    50, 53
  );
/* INSERT QUERY */
INSERT INTO STATUS(
  SCID, time, time_source, beacon_id,
  obc_temp, bat_temp, bat_volt, bat_current,
  charge_current, ant_dep, ops_mode,
  data_pend, reboot_cnt, rail_stat,
  rx_temp, tx_temp, pa_temp, rx_floor
)
VALUES
  (
    16962, '10/01/2020 10:00', 1, 19,-25,
    -26, 8, 36, 46, 0, 10, 52, 0, 4, 25, 26,
    50, 47
  );
/* INSERT QUERY */
INSERT INTO STATUS(
  SCID, time, time_source, beacon_id,
  obc_temp, bat_temp, bat_volt, bat_current,
  charge_current, ant_dep, ops_mode,
  data_pend, reboot_cnt, rail_stat,
  rx_temp, tx_temp, pa_temp, rx_floor
)
VALUES
  (
    16962, '11/01/2020 10:00', 1, 20,-23,
    -23, 8, 40, 50, 1, 10, 75, 0, 1, 23, 23,
    50, 6
  );
/* INSERT QUERY */
INSERT INTO STATUS(
  SCID, time, time_source, beacon_id,
  obc_temp, bat_temp, bat_volt, bat_current,
  charge_current, ant_dep, ops_mode,
  data_pend, reboot_cnt, rail_stat,
  rx_temp, tx_temp, pa_temp, rx_floor
)
VALUES
  (
    16962, '12/01/2020 10:00', 1, 21,-20,
    -21, 8, 44, 54, 1, 10, 26, 0, 2, 20, 21,
    50, 93
  );
/* INSERT QUERY */
INSERT INTO STATUS(
  SCID, time, time_source, beacon_id,
  obc_temp, bat_temp, bat_volt, bat_current,
  charge_current, ant_dep, ops_mode,
  data_pend, reboot_cnt, rail_stat,
  rx_temp, tx_temp, pa_temp, rx_floor
)
VALUES
  (
    16962, '13/01/2020 10:00', 1, 22,-18,
    -18, 7, 48, 58, 1, 10, 87, 0, 5, 18, 18,
    50, 7
  );
/* INSERT QUERY */
INSERT INTO STATUS(
  SCID, time, time_source, beacon_id,
  obc_temp, bat_temp, bat_volt, bat_current,
  charge_current, ant_dep, ops_mode,
  data_pend, reboot_cnt, rail_stat,
  rx_temp, tx_temp, pa_temp, rx_floor
)
VALUES
  (
    16962, '14/01/2020 10:00', 1, 23,-16,
    -16, 7, 53, 63, 1, 10, 111, 0, 3, 16, 16,
    50, 57
  );
/* INSERT QUERY */
INSERT INTO STATUS(
  SCID, time, time_source, beacon_id,
  obc_temp, bat_temp, bat_volt, bat_current,
  charge_current, ant_dep, ops_mode,
  data_pend, reboot_cnt, rail_stat,
  rx_temp, tx_temp, pa_temp, rx_floor
)
VALUES
  (
    16962, '15/01/2020 10:00', 1, 24,-14,
    -14, 7, 57, 67, 1, 10, 76, 0, 3, 14, 14,
    50, 92
  );
/* INSERT QUERY */
INSERT INTO STATUS(
  SCID, time, time_source, beacon_id,
  obc_temp, bat_temp, bat_volt, bat_current,
  charge_current, ant_dep, ops_mode,
  data_pend, reboot_cnt, rail_stat,
  rx_temp, tx_temp, pa_temp, rx_floor
)
VALUES
  (
    16962, '16/01/2020 10:00', 1, 25,-11,
    -12, 6, 61, 71, 1, 10, 44, 0, 2, 11, 12,
    50, 58
  );
/* INSERT QUERY */
INSERT INTO STATUS(
  SCID, time, time_source, beacon_id,
  obc_temp, bat_temp, bat_volt, bat_current,
  charge_current, ant_dep, ops_mode,
  data_pend, reboot_cnt, rail_stat,
  rx_temp, tx_temp, pa_temp, rx_floor
)
VALUES
  (
    16962, '17/01/2020 10:00', 1, 26,-9,
    -10, 6, 65, 75, 1, 10, 47, 0, 4, 9, 10, 50,
    44
  );
/* INSERT QUERY */
INSERT INTO STATUS(
  SCID, time, time_source, beacon_id,
  obc_temp, bat_temp, bat_volt, bat_current,
  charge_current, ant_dep, ops_mode,
  data_pend, reboot_cnt, rail_stat,
  rx_temp, tx_temp, pa_temp, rx_floor
)
VALUES
  (
    16962, '18/01/2020 10:00', 1, 27,-7,
    -8, 6, 69, 79, 1, 10, 102, 0, 3, 7, 8, 50,
    99
  );
/* INSERT QUERY */
INSERT INTO STATUS(
  SCID, time, time_source, beacon_id,
  obc_temp, bat_temp, bat_volt, bat_current,
  charge_current, ant_dep, ops_mode,
  data_pend, reboot_cnt, rail_stat,
  rx_temp, tx_temp, pa_temp, rx_floor
)
VALUES
  (
    16962, '19/01/2020 10:00', 1, 28,-5,
    -6, 6, 73, 83, 1, 10, 105, 0, 5, 5, 6, 50,
    108
  );
/* INSERT QUERY */
INSERT INTO STATUS(
  SCID, time, time_source, beacon_id,
  obc_temp, bat_temp, bat_volt, bat_current,
  charge_current, ant_dep, ops_mode,
  data_pend, reboot_cnt, rail_stat,
  rx_temp, tx_temp, pa_temp, rx_floor
)
VALUES
  (
    16962, '20/01/2020 10:00', 1, 29,-3,
    -4, 5, 77, 87, 1, 10, 22, 0, 5, 3, 4, 50,
    33
  );
/* INSERT QUERY */
INSERT INTO STATUS(
  SCID, time, time_source, beacon_id,
  obc_temp, bat_temp, bat_volt, bat_current,
  charge_current, ant_dep, ops_mode,
  data_pend, reboot_cnt, rail_stat,
  rx_temp, tx_temp, pa_temp, rx_floor
)
VALUES
  (
    16962, '21/01/2020 10:00', 1, 30,-2,
    -2, 5, 81, 91, 1, 10, 143, 0, 2, 2, 2, 50,
    93
  );
/* INSERT QUERY */
INSERT INTO STATUS(
  SCID, time, time_source, beacon_id,
  obc_temp, bat_temp, bat_volt, bat_current,
  charge_current, ant_dep, ops_mode,
  data_pend, reboot_cnt, rail_stat,
  rx_temp, tx_temp, pa_temp, rx_floor
)
VALUES
  (
    16962, '22/01/2020 10:00', 1, 31, 0,
    0, 5, 85, 95, 1, 10, 96, 0, 3, 0, 0, 50, 110
  );
/* INSERT QUERY */
INSERT INTO STATUS(
  SCID, time, time_source, beacon_id,
  obc_temp, bat_temp, bat_volt, bat_current,
  charge_current, ant_dep, ops_mode,
  data_pend, reboot_cnt, rail_stat,
  rx_temp, tx_temp, pa_temp, rx_floor
)
VALUES
  (
    16962, '23/01/2020 10:00', 1, 32, 2,
    2, 4, 89, 99, 1, 10, 117, 0, 0,-2,-2, 50,
    72
  );
/* INSERT QUERY */
INSERT INTO STATUS(
  SCID, time, time_source, beacon_id,
  obc_temp, bat_temp, bat_volt, bat_current,
  charge_current, ant_dep, ops_mode,
  data_pend, reboot_cnt, rail_stat,
  rx_temp, tx_temp, pa_temp, rx_floor
)
VALUES
  (
    16962, '24/01/2020 10:00', 1, 33, 4,
    3, 4, 93, 103, 1, 10, 99, 0, 5,-4,-3, 50,
    125
  );
/* INSERT QUERY */
INSERT INTO STATUS(
  SCID, time, time_source, beacon_id,
  obc_temp, bat_temp, bat_volt, bat_current,
  charge_current, ant_dep, ops_mode,
  data_pend, reboot_cnt, rail_stat,
  rx_temp, tx_temp, pa_temp, rx_floor
)
VALUES
  (
    16962, '25/01/2020 10:00', 1, 34, 5,
    5, 4, 97, 107, 1, 10, 79, 0, 0,-5,-5, 50,
    92
  );
/* INSERT QUERY */
INSERT INTO STATUS(
  SCID, time, time_source, beacon_id,
  obc_temp, bat_temp, bat_volt, bat_current,
  charge_current, ant_dep, ops_mode,
  data_pend, reboot_cnt, rail_stat,
  rx_temp, tx_temp, pa_temp, rx_floor
)
VALUES
  (
    16962, '26/01/2020 10:00', 1, 35, 7,
    6, 5, 101, 111, 1, 10, 68, 0, 0,-7,-6,
    50, 98
  );
/* INSERT QUERY */
INSERT INTO STATUS(
  SCID, time, time_source, beacon_id,
  obc_temp, bat_temp, bat_volt, bat_current,
  charge_current, ant_dep, ops_mode,
  data_pend, reboot_cnt, rail_stat,
  rx_temp, tx_temp, pa_temp, rx_floor
)
VALUES
  (
    16962, '27/01/2020 10:00', 1, 36, 8,
    8, 5, 105, 115, 1, 10, 39, 0, 3,-8,-8,
    50, 15
  );
/* INSERT QUERY */
INSERT INTO STATUS(
  SCID, time, time_source, beacon_id,
  obc_temp, bat_temp, bat_volt, bat_current,
  charge_current, ant_dep, ops_mode,
  data_pend, reboot_cnt, rail_stat,
  rx_temp, tx_temp, pa_temp, rx_floor
)
VALUES
  (
    16962, '28/01/2020 10:00', 1, 27, 10,
    9, 5, 109, 119, 1, 10, 37, 0, 0,-10,-9,
    50, 111
  );
/* INSERT QUERY */
INSERT INTO STATUS(
  SCID, time, time_source, beacon_id,
  obc_temp, bat_temp, bat_volt, bat_current,
  charge_current, ant_dep, ops_mode,
  data_pend, reboot_cnt, rail_stat,
  rx_temp, tx_temp, pa_temp, rx_floor
)
VALUES
  (
    16962, '29/01/2020 10:00', 1, 28, 11,
    11, 5, 113, 123, 1, 10, 145, 0, 0,-11,
    -11, 50, 8
  );
/* INSERT QUERY */
INSERT INTO STATUS(
  SCID, time, time_source, beacon_id,
  obc_temp, bat_temp, bat_volt, bat_current,
  charge_current, ant_dep, ops_mode,
  data_pend, reboot_cnt, rail_stat,
  rx_temp, tx_temp, pa_temp, rx_floor
)
VALUES
  (
    16962, '30/01/2020 10:00', 1, 29, 12,
    12, 6, 117, 127, 1, 10, 150, 0, 5,-12,
    -12, 50, 121
  );
/* INSERT QUERY */
INSERT INTO STATUS(
  SCID, time, time_source, beacon_id,
  obc_temp, bat_temp, bat_volt, bat_current,
  charge_current, ant_dep, ops_mode,
  data_pend, reboot_cnt, rail_stat,
  rx_temp, tx_temp, pa_temp, rx_floor
)
VALUES
  (
    16962, '31/01/2020 10:00', 1, 30, 13,
    13, 6, 121, 131, 1, 10, 118, 0, 1,-13,
    -13, 50, 86
  );
/* INSERT QUERY */
INSERT INTO STATUS(
  SCID, time, time_source, beacon_id,
  obc_temp, bat_temp, bat_volt, bat_current,
  charge_current, ant_dep, ops_mode,
  data_pend, reboot_cnt, rail_stat,
  rx_temp, tx_temp, pa_temp, rx_floor
)
VALUES
  (
    16962, '01/02/2020 10:00', 1, 31, 15,
    14, 6, 125, 135, 1, 10, 109, 0, 2,-15,
    -14, 50, 35
  );
/* INSERT QUERY */
INSERT INTO STATUS(
  SCID, time, time_source, beacon_id,
  obc_temp, bat_temp, bat_volt, bat_current,
  charge_current, ant_dep, ops_mode,
  data_pend, reboot_cnt, rail_stat,
  rx_temp, tx_temp, pa_temp, rx_floor
)
VALUES
  (
    16962, '02/02/2020 10:00', 1, 32, 16,
    15, 7, 129, 139, 1, 10, 24, 0, 4,-16,-15,
    50, 65
  );
/* INSERT QUERY */
INSERT INTO STATUS(
  SCID, time, time_source, beacon_id,
  obc_temp, bat_temp, bat_volt, bat_current,
  charge_current, ant_dep, ops_mode,
  data_pend, reboot_cnt, rail_stat,
  rx_temp, tx_temp, pa_temp, rx_floor
)
VALUES
  (
    16962, '03/02/2020 10:00', 1, 33, 17,
    17, 7, 133, 143, 1, 10, 61, 0, 0,-17,-17,
    50, 85
  );
/* INSERT QUERY */
INSERT INTO STATUS(
  SCID, time, time_source, beacon_id,
  obc_temp, bat_temp, bat_volt, bat_current,
  charge_current, ant_dep, ops_mode,
  data_pend, reboot_cnt, rail_stat,
  rx_temp, tx_temp, pa_temp, rx_floor
)
VALUES
  (
    16962, '04/02/2020 10:00', 1, 34, 18,
    17, 7, 137, 147, 1, 10, 87, 0, 1,-18,-17,
    50, 49
  );
/* INSERT QUERY */
INSERT INTO STATUS(
  SCID, time, time_source, beacon_id,
  obc_temp, bat_temp, bat_volt, bat_current,
  charge_current, ant_dep, ops_mode,
  data_pend, reboot_cnt, rail_stat,
  rx_temp, tx_temp, pa_temp, rx_floor
)
VALUES
  (
    16962, '05/02/2020 10:00', 1, 35, 19,
    18, 8, 141, 151, 1, 10, 12, 0, 2,-19,-18,
    50, 64
  );
/* INSERT QUERY */
INSERT INTO STATUS(
  SCID, time, time_source, beacon_id,
  obc_temp, bat_temp, bat_volt, bat_current,
  charge_current, ant_dep, ops_mode,
  data_pend, reboot_cnt, rail_stat,
  rx_temp, tx_temp, pa_temp, rx_floor
)
VALUES
  (
    16962, '06/02/2020 10:00', 1, 36, 19,
    19, 8, 145, 155, 1, 10, 91, 0, 2,-19,-19,
    50, 126
  );
/* INSERT QUERY */
INSERT INTO STATUS(
  SCID, time, time_source, beacon_id,
  obc_temp, bat_temp, bat_volt, bat_current,
  charge_current, ant_dep, ops_mode,
  data_pend, reboot_cnt, rail_stat,
  rx_temp, tx_temp, pa_temp, rx_floor
)
VALUES
  (
    16962, '07/02/2020 10:00', 1, 44, 20,
    20, 8, 149, 159, 1, 10, 104, 0, 4,-20,
    -20, 50, 81
  );
/* INSERT QUERY */
INSERT INTO STATUS(
  SCID, time, time_source, beacon_id,
  obc_temp, bat_temp, bat_volt, bat_current,
  charge_current, ant_dep, ops_mode,
  data_pend, reboot_cnt, rail_stat,
  rx_temp, tx_temp, pa_temp, rx_floor
)
VALUES
  (
    16962, '08/02/2020 10:00', 1, 45, 21,
    21, 9, 154, 164, 1, 1, 75, 0, 0,-21,-21,
    50, 9
  );
/* INSERT QUERY */
INSERT INTO STATUS(
  SCID, time, time_source, beacon_id,
  obc_temp, bat_temp, bat_volt, bat_current,
  charge_current, ant_dep, ops_mode,
  data_pend, reboot_cnt, rail_stat,
  rx_temp, tx_temp, pa_temp, rx_floor
)
VALUES
  (
    16962, '09/02/2020 10:00', 1, 46, 22,
    22, 9, 158, 168, 1, 1, 14, 0, 3,-22,-22,
    50, 41
  );
/* INSERT QUERY */
INSERT INTO STATUS(
  SCID, time, time_source, beacon_id,
  obc_temp, bat_temp, bat_volt, bat_current,
  charge_current, ant_dep, ops_mode,
  data_pend, reboot_cnt, rail_stat,
  rx_temp, tx_temp, pa_temp, rx_floor
)
VALUES
  (
    16962, '10/02/2020 10:00', 1, 47, 22,
    22, 9, 162, 172, 1, 1, 18, 0, 5,-22,-22,
    50, 62
  );
/* INSERT QUERY */
INSERT INTO STATUS(
  SCID, time, time_source, beacon_id,
  obc_temp, bat_temp, bat_volt, bat_current,
  charge_current, ant_dep, ops_mode,
  data_pend, reboot_cnt, rail_stat,
  rx_temp, tx_temp, pa_temp, rx_floor
)
VALUES
  (
    16962, '11/02/2020 10:00', 1, 48, 23,
    23, 9, 166, 176, 1, 1, 34, 0, 5,-23,-23,
    50, 110
  );
/* INSERT QUERY */
INSERT INTO STATUS(
  SCID, time, time_source, beacon_id,
  obc_temp, bat_temp, bat_volt, bat_current,
  charge_current, ant_dep, ops_mode,
  data_pend, reboot_cnt, rail_stat,
  rx_temp, tx_temp, pa_temp, rx_floor
)
VALUES
  (
    16962, '12/02/2020 10:00', 1, 49, 23,
    23, 10, 170, 180, 1, 1, 62, 0, 4,-23,-23,
    50, 10
  );
/* INSERT QUERY */
INSERT INTO STATUS(
  SCID, time, time_source, beacon_id,
  obc_temp, bat_temp, bat_volt, bat_current,
  charge_current, ant_dep, ops_mode,
  data_pend, reboot_cnt, rail_stat,
  rx_temp, tx_temp, pa_temp, rx_floor
)
VALUES
  (
    16962, '13/02/2020 10:00', 1, 50, 24,
    24, 10, 174, 184, 1, 1, 146, 0, 2,-24,
    -24, 50, 10
  );
/* INSERT QUERY */
INSERT INTO STATUS(
  SCID, time, time_source, beacon_id,
  obc_temp, bat_temp, bat_volt, bat_current,
  charge_current, ant_dep, ops_mode,
  data_pend, reboot_cnt, rail_stat,
  rx_temp, tx_temp, pa_temp, rx_floor
)
VALUES
  (
    16962, '14/02/2020 10:00', 1, 51, 24,
    24, 10, 178, 188, 1, 1, 53, 0, 3,-24,-24,
    50, 18
  );
/* INSERT QUERY */
INSERT INTO STATUS(
  SCID, time, time_source, beacon_id,
  obc_temp, bat_temp, bat_volt, bat_current,
  charge_current, ant_dep, ops_mode,
  data_pend, reboot_cnt, rail_stat,
  rx_temp, tx_temp, pa_temp, rx_floor
)
VALUES
  (
    16962, '15/02/2020 10:00', 1, 52, 24,
    24, 11, 182, 192, 1, 1, 128, 0, 1,-24,
    -24, 50, 105
  );
/* INSERT QUERY */
INSERT INTO STATUS(
  SCID, time, time_source, beacon_id,
  obc_temp, bat_temp, bat_volt, bat_current,
  charge_current, ant_dep, ops_mode,
  data_pend, reboot_cnt, rail_stat,
  rx_temp, tx_temp, pa_temp, rx_floor
)
VALUES
  (
    16962, '16/02/2020 10:00', 1, 53, 25,
    25, 11, 186, 196, 1, 1, 48, 0, 4,-25,-25,
    50, 5
  );
/* INSERT QUERY */
INSERT INTO STATUS(
  SCID, time, time_source, beacon_id,
  obc_temp, bat_temp, bat_volt, bat_current,
  charge_current, ant_dep, ops_mode,
  data_pend, reboot_cnt, rail_stat,
  rx_temp, tx_temp, pa_temp, rx_floor
)
VALUES
  (
    16962, '17/02/2020 10:00', 1, 54, 25,
    25, 11, 190, 200, 1, 1, 22, 0, 2,-25,-25,
    50, 41
  );
/* INSERT QUERY */
INSERT INTO STATUS(
  SCID, time, time_source, beacon_id,
  obc_temp, bat_temp, bat_volt, bat_current,
  charge_current, ant_dep, ops_mode,
  data_pend, reboot_cnt, rail_stat,
  rx_temp, tx_temp, pa_temp, rx_floor
)
VALUES
  (
    16962, '18/02/2020 10:00', 1, 55, 25,
    25, 12, 194, 204, 1, 1, 96, 0, 0,-25,-25,
    50, 16
  );
/* INSERT QUERY */
INSERT INTO STATUS(
  SCID, time, time_source, beacon_id,
  obc_temp, bat_temp, bat_volt, bat_current,
  charge_current, ant_dep, ops_mode,
  data_pend, reboot_cnt, rail_stat,
  rx_temp, tx_temp, pa_temp, rx_floor
)
VALUES
  (
    16962, '19/02/2020 10:00', 1, 56, 25,
    25, 12, 198, 208, 1, 1, 63, 0, 2,-25,-25,
    50, 82
  );
/* INSERT QUERY */
INSERT INTO STATUS(
  SCID, time, time_source, beacon_id,
  obc_temp, bat_temp, bat_volt, bat_current,
  charge_current, ant_dep, ops_mode,
  data_pend, reboot_cnt, rail_stat,
  rx_temp, tx_temp, pa_temp, rx_floor
)
VALUES
  (
    16962, '20/02/2020 10:00', 1, 57, 25,
    25, 11, 198, 208, 1, 1, 42, 0, 2,-25,-25,
    50, 109
  );
/* INSERT QUERY */
INSERT INTO STATUS(
  SCID, time, time_source, beacon_id,
  obc_temp, bat_temp, bat_volt, bat_current,
  charge_current, ant_dep, ops_mode,
  data_pend, reboot_cnt, rail_stat,
  rx_temp, tx_temp, pa_temp, rx_floor
)
VALUES
  (
    16962, '21/02/2020 10:00', 1, 58, 25,
    25, 11, 194, 204, 1, 1, 41, 0, 5,-25,-25,
    50, 104
  );
/* INSERT QUERY */
INSERT INTO STATUS(
  SCID, time, time_source, beacon_id,
  obc_temp, bat_temp, bat_volt, bat_current,
  charge_current, ant_dep, ops_mode,
  data_pend, reboot_cnt, rail_stat,
  rx_temp, tx_temp, pa_temp, rx_floor
)
VALUES
  (
    16962, '22/02/2020 10:00', 1, 59, 25,
    25, 10, 190, 200, 1, 1, 95, 0, 4,-25,-25,
    50, 89
  );
/* INSERT QUERY */
INSERT INTO STATUS(
  SCID, time, time_source, beacon_id,
  obc_temp, bat_temp, bat_volt, bat_current,
  charge_current, ant_dep, ops_mode,
  data_pend, reboot_cnt, rail_stat,
  rx_temp, tx_temp, pa_temp, rx_floor
)
VALUES
  (
    16962, '23/02/2020 10:00', 1, 60, 25,
    25, 10, 186, 196, 1, 1, 58, 0, 5,-25,-25,
    50, 68
  );
/* INSERT QUERY */
INSERT INTO STATUS(
  SCID, time, time_source, beacon_id,
  obc_temp, bat_temp, bat_volt, bat_current,
  charge_current, ant_dep, ops_mode,
  data_pend, reboot_cnt, rail_stat,
  rx_temp, tx_temp, pa_temp, rx_floor
)
VALUES
  (
    16962, '24/02/2020 10:00', 1, 61, 24,
    24, 10, 182, 192, 1, 1, 81, 0, 0,-24,-24,
    50, 55
  );
/* INSERT QUERY */
INSERT INTO STATUS(
  SCID, time, time_source, beacon_id,
  obc_temp, bat_temp, bat_volt, bat_current,
  charge_current, ant_dep, ops_mode,
  data_pend, reboot_cnt, rail_stat,
  rx_temp, tx_temp, pa_temp, rx_floor
)
VALUES
  (
    16962, '25/02/2020 10:00', 1, 62, 24,
    24, 9, 178, 188, 1, 1, 92, 0, 0,-24,-24,
    50, 69
  );
/* INSERT QUERY */
INSERT INTO STATUS(
  SCID, time, time_source, beacon_id,
  obc_temp, bat_temp, bat_volt, bat_current,
  charge_current, ant_dep, ops_mode,
  data_pend, reboot_cnt, rail_stat,
  rx_temp, tx_temp, pa_temp, rx_floor
)
VALUES
  (
    16962, '26/02/2020 10:00', 1, 63, 24,
    24, 9, 174, 184, 1, 1, 79, 0, 2,-24,-24,
    50, 17
  );
/* INSERT QUERY */
INSERT INTO STATUS(
  SCID, time, time_source, beacon_id,
  obc_temp, bat_temp, bat_volt, bat_current,
  charge_current, ant_dep, ops_mode,
  data_pend, reboot_cnt, rail_stat,
  rx_temp, tx_temp, pa_temp, rx_floor
)
VALUES
  (
    16962, '27/02/2020 10:00', 1, 64, 23,
    23, 9, 170, 180, 1, 1, 60, 0, 0,-23,-23,
    50, 56
  );
/* INSERT QUERY */
INSERT INTO STATUS(
  SCID, time, time_source, beacon_id,
  obc_temp, bat_temp, bat_volt, bat_current,
  charge_current, ant_dep, ops_mode,
  data_pend, reboot_cnt, rail_stat,
  rx_temp, tx_temp, pa_temp, rx_floor
)
VALUES
  (
    16962, '28/02/2020 10:00', 1, 65, 23,
    23, 9, 166, 176, 1, 1, 146, 0, 0,-23,-23,
    50, 0
  );
/* INSERT QUERY */
INSERT INTO STATUS(
  SCID, time, time_source, beacon_id,
  obc_temp, bat_temp, bat_volt, bat_current,
  charge_current, ant_dep, ops_mode,
  data_pend, reboot_cnt, rail_stat,
  rx_temp, tx_temp, pa_temp, rx_floor
)
VALUES
  (
    16962, '29/02/2020 10:00', 1, 66, 22,
    22, 8, 162, 172, 1, 1, 131, 0, 5,-22,-22,
    50, 5
  );
/* INSERT QUERY */
INSERT INTO STATUS(
  SCID, time, time_source, beacon_id,
  obc_temp, bat_temp, bat_volt, bat_current,
  charge_current, ant_dep, ops_mode,
  data_pend, reboot_cnt, rail_stat,
  rx_temp, tx_temp, pa_temp, rx_floor
)
VALUES
  (
    16962, '01/03/2020 10:00', 1, 67, 22,
    22, 8, 158, 168, 1, 1, 107, 0, 1,-22,-22,
    50, 87
  );
/* INSERT QUERY */
INSERT INTO STATUS(
  SCID, time, time_source, beacon_id,
  obc_temp, bat_temp, bat_volt, bat_current,
  charge_current, ant_dep, ops_mode,
  data_pend, reboot_cnt, rail_stat,
  rx_temp, tx_temp, pa_temp, rx_floor
)
VALUES
  (
    16962, '02/03/2020 10:00', 1, 68, 21,
    21, 8, 154, 164, 1, 1, 129, 0, 0,-21,-21,
    50, 82
  );
/* INSERT QUERY */
INSERT INTO STATUS(
  SCID, time, time_source, beacon_id,
  obc_temp, bat_temp, bat_volt, bat_current,
  charge_current, ant_dep, ops_mode,
  data_pend, reboot_cnt, rail_stat,
  rx_temp, tx_temp, pa_temp, rx_floor
)
VALUES
  (
    16962, '03/03/2020 10:00', 1, 69, 20,
    20, 7, 149, 159, 1, 10, 122, 0, 1,-20,
    -20, 50, 111
  );
/* INSERT QUERY */
INSERT INTO STATUS(
  SCID, time, time_source, beacon_id,
  obc_temp, bat_temp, bat_volt, bat_current,
  charge_current, ant_dep, ops_mode,
  data_pend, reboot_cnt, rail_stat,
  rx_temp, tx_temp, pa_temp, rx_floor
)
VALUES
  (
    16962, '04/03/2020 10:00', 1, 70, 19,
    20, 7, 145, 155, 1, 10, 110, 0, 3,-19,
    -20, 50, 88
  );
/* INSERT QUERY */
INSERT INTO STATUS(
  SCID, time, time_source, beacon_id,
  obc_temp, bat_temp, bat_volt, bat_current,
  charge_current, ant_dep, ops_mode,
  data_pend, reboot_cnt, rail_stat,
  rx_temp, tx_temp, pa_temp, rx_floor
)
VALUES
  (
    16962, '05/03/2020 10:00', 1, 71, 19,
    19, 7, 141, 151, 1, 10, 146, 0, 4,-19,
    -19, 50, 70
  );
/* INSERT QUERY */
INSERT INTO STATUS(
  SCID, time, time_source, beacon_id,
  obc_temp, bat_temp, bat_volt, bat_current,
  charge_current, ant_dep, ops_mode,
  data_pend, reboot_cnt, rail_stat,
  rx_temp, tx_temp, pa_temp, rx_floor
)
VALUES
  (
    16962, '06/03/2020 10:00', 1, 72, 18,
    18, 6, 137, 147, 1, 10, 146, 0, 1,-18,
    -18, 50, 59
  );
/* INSERT QUERY */
INSERT INTO STATUS(
  SCID, time, time_source, beacon_id,
  obc_temp, bat_temp, bat_volt, bat_current,
  charge_current, ant_dep, ops_mode,
  data_pend, reboot_cnt, rail_stat,
  rx_temp, tx_temp, pa_temp, rx_floor
)
VALUES
  (
    16962, '07/03/2020 10:00', 1, 73, 17,
    17, 6, 133, 143, 1, 10, 78, 0, 4,-17,-17,
    50, 103
  );
/* INSERT QUERY */
INSERT INTO STATUS(
  SCID, time, time_source, beacon_id,
  obc_temp, bat_temp, bat_volt, bat_current,
  charge_current, ant_dep, ops_mode,
  data_pend, reboot_cnt, rail_stat,
  rx_temp, tx_temp, pa_temp, rx_floor
)
VALUES
  (
    16962, '08/03/2020 10:00', 1, 74, 16,
    16, 6, 129, 139, 1, 10, 12, 0, 0,-16,-16,
    50, 90
  );
/* INSERT QUERY */
INSERT INTO STATUS(
  SCID, time, time_source, beacon_id,
  obc_temp, bat_temp, bat_volt, bat_current,
  charge_current, ant_dep, ops_mode,
  data_pend, reboot_cnt, rail_stat,
  rx_temp, tx_temp, pa_temp, rx_floor
)
VALUES
  (
    16962, '09/03/2020 10:00', 1, 75, 15,
    15, 6, 125, 135, 1, 10, 147, 0, 0,-15,
    -15, 50, 115
  );
/* INSERT QUERY */
INSERT INTO STATUS(
  SCID, time, time_source, beacon_id,
  obc_temp, bat_temp, bat_volt, bat_current,
  charge_current, ant_dep, ops_mode,
  data_pend, reboot_cnt, rail_stat,
  rx_temp, tx_temp, pa_temp, rx_floor
)
VALUES
  (
    16962, '10/03/2020 10:00', 1, 76, 13,
    14, 5, 121, 131, 1, 10, 19, 0, 1,-13,-14,
    50, 47
  );
/* INSERT QUERY */
INSERT INTO STATUS(
  SCID, time, time_source, beacon_id,
  obc_temp, bat_temp, bat_volt, bat_current,
  charge_current, ant_dep, ops_mode,
  data_pend, reboot_cnt, rail_stat,
  rx_temp, tx_temp, pa_temp, rx_floor
)
VALUES
  (
    16962, '11/03/2020 10:00', 1, 77, 12,
    12, 5, 117, 127, 1, 10, 96, 0, 2,-12,-12,
    50, 1
  );
/* INSERT QUERY */
INSERT INTO STATUS(
  SCID, time, time_source, beacon_id,
  obc_temp, bat_temp, bat_volt, bat_current,
  charge_current, ant_dep, ops_mode,
  data_pend, reboot_cnt, rail_stat,
  rx_temp, tx_temp, pa_temp, rx_floor
)
VALUES
  (
    16962, '12/03/2020 10:00', 1, 78, 11,
    11, 5, 113, 123, 1, 10, 60, 0, 4,-11,-11,
    50, 44
  );
/* INSERT QUERY */
INSERT INTO STATUS(
  SCID, time, time_source, beacon_id,
  obc_temp, bat_temp, bat_volt, bat_current,
  charge_current, ant_dep, ops_mode,
  data_pend, reboot_cnt, rail_stat,
  rx_temp, tx_temp, pa_temp, rx_floor
)
VALUES
  (
    16962, '13/03/2020 10:00', 1, 79, 10,
    10, 4, 109, 119, 1, 10, 57, 0, 0,-10,-10,
    50, 68
  );
/* INSERT QUERY */
INSERT INTO STATUS(
  SCID, time, time_source, beacon_id,
  obc_temp, bat_temp, bat_volt, bat_current,
  charge_current, ant_dep, ops_mode,
  data_pend, reboot_cnt, rail_stat,
  rx_temp, tx_temp, pa_temp, rx_floor
)
VALUES
  (
    16962, '14/03/2020 10:00', 1, 80, 8,
    8, 4, 105, 115, 1, 10, 120, 0, 1,-8,-8,
    50, 96
  );
/* INSERT QUERY */
INSERT INTO STATUS(
  SCID, time, time_source, beacon_id,
  obc_temp, bat_temp, bat_volt, bat_current,
  charge_current, ant_dep, ops_mode,
  data_pend, reboot_cnt, rail_stat,
  rx_temp, tx_temp, pa_temp, rx_floor
)
VALUES
  (
    16962, '15/03/2020 10:00', 1, 81, 7,
    7, 4, 101, 111, 1, 10, 88, 0, 0,-7,-7,
    50, 36
  );
/* INSERT QUERY */
INSERT INTO STATUS(
  SCID, time, time_source, beacon_id,
  obc_temp, bat_temp, bat_volt, bat_current,
  charge_current, ant_dep, ops_mode,
  data_pend, reboot_cnt, rail_stat,
  rx_temp, tx_temp, pa_temp, rx_floor
)
VALUES
  (
    16962, '16/03/2020 10:00', 1, 82, 5,
    5, 5, 97, 107, 1, 10, 36, 0, 1,-5,-5, 50,
    118
  );
/* INSERT QUERY */
INSERT INTO STATUS(
  SCID, time, time_source, beacon_id,
  obc_temp, bat_temp, bat_volt, bat_current,
  charge_current, ant_dep, ops_mode,
  data_pend, reboot_cnt, rail_stat,
  rx_temp, tx_temp, pa_temp, rx_floor
)
VALUES
  (
    16962, '17/03/2020 10:00', 1, 83, 4,
    4, 5, 93, 103, 1, 10, 54, 0, 5,-4,-4, 50,
    26
  );
/* INSERT QUERY */
INSERT INTO STATUS(
  SCID, time, time_source, beacon_id,
  obc_temp, bat_temp, bat_volt, bat_current,
  charge_current, ant_dep, ops_mode,
  data_pend, reboot_cnt, rail_stat,
  rx_temp, tx_temp, pa_temp, rx_floor
)
VALUES
  (
    16962, '18/03/2020 10:00', 1, 84, 2,
    2, 5, 89, 99, 1, 10, 100, 0, 5,-2,-2, 50,
    53
  );
/* INSERT QUERY */
INSERT INTO STATUS(
  SCID, time, time_source, beacon_id,
  obc_temp, bat_temp, bat_volt, bat_current,
  charge_current, ant_dep, ops_mode,
  data_pend, reboot_cnt, rail_stat,
  rx_temp, tx_temp, pa_temp, rx_floor
)
VALUES
  (
    16962, '19/03/2020 10:00', 1, 85, 0,
    0, 5, 85, 95, 1, 10, 31, 0, 4, 0, 0, 50, 22
  );
/* INSERT QUERY */
INSERT INTO STATUS(
  SCID, time, time_source, beacon_id,
  obc_temp, bat_temp, bat_volt, bat_current,
  charge_current, ant_dep, ops_mode,
  data_pend, reboot_cnt, rail_stat,
  rx_temp, tx_temp, pa_temp, rx_floor
)
VALUES
  (
    16962, '20/03/2020 10:00', 1, 86,-2,
    -1, 6, 81, 91, 1, 10, 101, 0, 2, 2, 1, 50,
    62
  );
/* INSERT QUERY */
INSERT INTO STATUS(
  SCID, time, time_source, beacon_id,
  obc_temp, bat_temp, bat_volt, bat_current,
  charge_current, ant_dep, ops_mode,
  data_pend, reboot_cnt, rail_stat,
  rx_temp, tx_temp, pa_temp, rx_floor
)
VALUES
  (
    16962, '21/03/2020 10:00', 1, 87,-3,
    -3, 6, 77, 87, 1, 10, 65, 0, 2, 3, 3, 50,
    74
  );
/* INSERT QUERY */
INSERT INTO STATUS(
  SCID, time, time_source, beacon_id,
  obc_temp, bat_temp, bat_volt, bat_current,
  charge_current, ant_dep, ops_mode,
  data_pend, reboot_cnt, rail_stat,
  rx_temp, tx_temp, pa_temp, rx_floor
)
VALUES
  (
    16962, '22/03/2020 10:00', 1, 88,-5,
    -5, 6, 73, 83, 1, 10, 83, 0, 2, 5, 5, 50,
    109
  );
/* INSERT QUERY */
INSERT INTO STATUS(
  SCID, time, time_source, beacon_id,
  obc_temp, bat_temp, bat_volt, bat_current,
  charge_current, ant_dep, ops_mode,
  data_pend, reboot_cnt, rail_stat,
  rx_temp, tx_temp, pa_temp, rx_floor
)
VALUES
  (
    16962, '23/03/2020 10:00', 1, 89,-7,
    -7, 7, 69, 79, 1, 10, 28, 0, 4, 7, 7, 50,
    21
  );
/* INSERT QUERY */
INSERT INTO STATUS(
  SCID, time, time_source, beacon_id,
  obc_temp, bat_temp, bat_volt, bat_current,
  charge_current, ant_dep, ops_mode,
  data_pend, reboot_cnt, rail_stat,
  rx_temp, tx_temp, pa_temp, rx_floor
)
VALUES
  (
    16962, '24/03/2020 10:00', 1, 90,-9,
    -9, 7, 65, 75, 1, 10, 98, 0, 5, 9, 9, 50,
    51
  );
/* INSERT QUERY */
INSERT INTO STATUS(
  SCID, time, time_source, beacon_id,
  obc_temp, bat_temp, bat_volt, bat_current,
  charge_current, ant_dep, ops_mode,
  data_pend, reboot_cnt, rail_stat,
  rx_temp, tx_temp, pa_temp, rx_floor
)
VALUES
  (
    16962, '25/03/2020 10:00', 1, 91,-11,
    -11, 7, 61, 71, 1, 10, 150, 0, 4, 11, 11,
    50, 113
  );
/* INSERT QUERY */
INSERT INTO STATUS(
  SCID, time, time_source, beacon_id,
  obc_temp, bat_temp, bat_volt, bat_current,
  charge_current, ant_dep, ops_mode,
  data_pend, reboot_cnt, rail_stat,
  rx_temp, tx_temp, pa_temp, rx_floor
)
VALUES
  (
    16962, '26/03/2020 10:00', 1, 92,-14,
    -13, 8, 57, 67, 1, 10, 10, 0, 5, 14, 13,
    50, 61
  );
/* INSERT QUERY */
INSERT INTO STATUS(
  SCID, time, time_source, beacon_id,
  obc_temp, bat_temp, bat_volt, bat_current,
  charge_current, ant_dep, ops_mode,
  data_pend, reboot_cnt, rail_stat,
  rx_temp, tx_temp, pa_temp, rx_floor
)
VALUES
  (
    16962, '27/03/2020 10:00', 1, 93,-16,
    -15, 8, 53, 63, 1, 10, 105, 0, 0, 16, 15,
    50, 4
  );
/* INSERT QUERY */
INSERT INTO STATUS(
  SCID, time, time_source, beacon_id,
  obc_temp, bat_temp, bat_volt, bat_current,
  charge_current, ant_dep, ops_mode,
  data_pend, reboot_cnt, rail_stat,
  rx_temp, tx_temp, pa_temp, rx_floor
)
VALUES
  (
    16962, '28/03/2020 10:00', 1, 94,-18,
    -18, 8, 48, 58, 1, 10, 37, 0, 5, 18, 18,
    50, 95
  );
/* INSERT QUERY */
INSERT INTO STATUS(
  SCID, time, time_source, beacon_id,
  obc_temp, bat_temp, bat_volt, bat_current,
  charge_current, ant_dep, ops_mode,
  data_pend, reboot_cnt, rail_stat,
  rx_temp, tx_temp, pa_temp, rx_floor
)
VALUES
  (
    16962, '29/03/2020 10:00', 1, 95,-20,
    -20, 9, 44, 54, 1, 10, 115, 0, 3, 20, 20,
    50, 25
  );
/* INSERT QUERY */
INSERT INTO STATUS(
  SCID, time, time_source, beacon_id,
  obc_temp, bat_temp, bat_volt, bat_current,
  charge_current, ant_dep, ops_mode,
  data_pend, reboot_cnt, rail_stat,
  rx_temp, tx_temp, pa_temp, rx_floor
)
VALUES
  (
    16962, '30/03/2020 10:00', 1, 96,-23,
    -22, 9, 40, 50, 1, 10, 72, 0, 0, 23, 22,
    50, 2
  );
/* INSERT QUERY */
INSERT INTO STATUS(
  SCID, time, time_source, beacon_id,
  obc_temp, bat_temp, bat_volt, bat_current,
  charge_current, ant_dep, ops_mode,
  data_pend, reboot_cnt, rail_stat,
  rx_temp, tx_temp, pa_temp, rx_floor
)
VALUES
  (
    16962, '31/03/2020 10:00', 1, 97,-25,
    -25, 9, 36, 46, 1, 10, 139, 0, 2, 25, 25,
    50, 112
  );
/* INSERT QUERY */
INSERT INTO STATUS(
  SCID, time, time_source, beacon_id,
  obc_temp, bat_temp, bat_volt, bat_current,
  charge_current, ant_dep, ops_mode,
  data_pend, reboot_cnt, rail_stat,
  rx_temp, tx_temp, pa_temp, rx_floor
)
VALUES
  (
    16962, '01/04/2020 10:00', 1, 98,-28,
    -27, 9, 32, 42, 1, 10, 142, 0, 5, 28, 27,
    50, 60
  );
/* INSERT QUERY */
INSERT INTO STATUS(
  SCID, time, time_source, beacon_id,
  obc_temp, bat_temp, bat_volt, bat_current,
  charge_current, ant_dep, ops_mode,
  data_pend, reboot_cnt, rail_stat,
  rx_temp, tx_temp, pa_temp, rx_floor
)
VALUES
  (
    16962, '02/04/2020 10:00', 1, 99,-30,
    -30, 10, 28, 38, 1, 10, 15, 0, 5, 30, 30,
    50, 85
  );
/* INSERT QUERY */
INSERT INTO STATUS(
  SCID, time, time_source, beacon_id,
  obc_temp, bat_temp, bat_volt, bat_current,
  charge_current, ant_dep, ops_mode,
  data_pend, reboot_cnt, rail_stat,
  rx_temp, tx_temp, pa_temp, rx_floor
)
VALUES
  (
    16962, '03/04/2020 10:00', 1, 100,
    -33,-32, 10, 24, 34, 1, 10, 141, 0, 3,
    33, 32, 50, 86
  );
/* INSERT QUERY */
INSERT INTO STATUS(
  SCID, time, time_source, beacon_id,
  obc_temp, bat_temp, bat_volt, bat_current,
  charge_current, ant_dep, ops_mode,
  data_pend, reboot_cnt, rail_stat,
  rx_temp, tx_temp, pa_temp, rx_floor
)
VALUES
  (
    16962, '04/04/2020 10:00', 1, 101,
    -36,-35, 10, 20, 30, 1, 10, 32, 1, 0, 36,
    35, 50, 93
  );
/* INSERT QUERY */
INSERT INTO STATUS(
  SCID, time, time_source, beacon_id,
  obc_temp, bat_temp, bat_volt, bat_current,
  charge_current, ant_dep, ops_mode,
  data_pend, reboot_cnt, rail_stat,
  rx_temp, tx_temp, pa_temp, rx_floor
)
VALUES
  (
    16962, '05/04/2020 10:00', 1, 102,
    -38,-38, 11, 16, 26, 1, 10, 48, 2, 2, 38,
    38, 50, 98
  );
/* INSERT QUERY */
INSERT INTO STATUS(
  SCID, time, time_source, beacon_id,
  obc_temp, bat_temp, bat_volt, bat_current,
  charge_current, ant_dep, ops_mode,
  data_pend, reboot_cnt, rail_stat,
  rx_temp, tx_temp, pa_temp, rx_floor
)
VALUES
  (
    16962, '06/04/2020 10:00', 1, 103,
    -41,-41, 11, 12, 22, 1, 10, 26, 5, 5, 41,
    41, 50, 30
  );
/* INSERT QUERY */
INSERT INTO STATUS(
  SCID, time, time_source, beacon_id,
  obc_temp, bat_temp, bat_volt, bat_current,
  charge_current, ant_dep, ops_mode,
  data_pend, reboot_cnt, rail_stat,
  rx_temp, tx_temp, pa_temp, rx_floor
)
VALUES
  (
    16962, '07/04/2020 10:00', 1, 104,
    -44,-44, 11, 8, 18, 1, 10, 136, 10, 5,
    44, 44, 50, 120
  );
/* INSERT QUERY */
INSERT INTO STATUS(
  SCID, time, time_source, beacon_id,
  obc_temp, bat_temp, bat_volt, bat_current,
  charge_current, ant_dep, ops_mode,
  data_pend, reboot_cnt, rail_stat,
  rx_temp, tx_temp, pa_temp, rx_floor
)
VALUES
  (
    16962, '08/04/2020 10:00', 1, 105,
    -47,-47, 12, 4, 14, 1, 10, 143, 20, 1,
    47, 47, 50, 82
  );
/* INSERT QUERY */
INSERT INTO STATUS(
  SCID, time, time_source, beacon_id,
  obc_temp, bat_temp, bat_volt, bat_current,
  charge_current, ant_dep, ops_mode,
  data_pend, reboot_cnt, rail_stat,
  rx_temp, tx_temp, pa_temp, rx_floor
)
VALUES
  (
    16962, '09/04/2020 10:00', 1, 106,
    -50,-50, 12, 0, 10, 1, 10, 84, 100, 1,
    50, 50, 50, 47
  );
