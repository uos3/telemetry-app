/* DROP OLD AND CREATE TABLE */
DROP TABLE IF EXISTS DUMMYGPS;
CREATE TABLE DUMMYGPS(
  preamble BIGINT(32),
  syncWord BIGINT(32),
  packType DECIMAL(10, 2),
  SCID DECIMAL(10, 2),
  SCTime VARCHAR(100),
  timeSource DECIMAL(10, 2),
  seqID DECIMAL(10, 2),
  OBCTemp DECIMAL(10, 2),
  battTemp DECIMAL(10, 2),
  battVolt DECIMAL(10, 2),
  battCurrent DECIMAL(10, 2),
  chargeCurrent DECIMAL(10, 2),
  antDep DECIMAL(10, 2),
  dataPending DECIMAL(10, 2),
  rebootCnt DECIMAL(10, 2),
  rails1 DECIMAL(10, 2),
  rails2 DECIMAL(10, 2),
  rails3 DECIMAL(10, 2),
  rails4 DECIMAL(10, 2),
  rails5 DECIMAL(10, 2),
  rails6 DECIMAL(10, 2),
  RXTemp DECIMAL(10, 2),
  TXTemp DECIMAL(10, 2),
  PATemp DECIMAL(10, 2),
  RXNoiseFloor DECIMAL(10, 2),
  seqIDPayload DECIMAL(10, 2),
  payloadTimeStamp VARCHAR(100),
  lat DECIMAL(10, 2),
  lon DECIMAL(10, 2),
  alt DECIMAL(10, 2),
  HDOP DECIMAL(10, 2),
  VDOP DECIMAL(10, 2),
  PDOP DECIMAL(10, 2),
  TDOP DECIMAL(10, 2),
  hash BIGINT(64),
  CRC BIGINT(64)
);
/* INSERT QUERY */
INSERT INTO DUMMYGPS(
  preamble, syncWord, packType, SCID,
  SCTime, timeSource, seqID, OBCTemp,
  battTemp, battVolt, battCurrent,
  chargeCurrent, antDep, dataPending,
  rebootCnt, rails1, rails2, rails3,
  rails4, rails5, rails6, RXTemp, TXTemp,
  PATemp, RXNoiseFloor, seqIDPayload, payloadTimeStamp,
  lat, lon, alt, HDOP, VDOP, PDOP, TDOP,
  hash, CRC
)
VALUES
  (
    10101010101010101010101010101010,
    10101010101010101010101010101010,
    2, 16962, '01/01/2020 10:00', 0, 10080,
    -24, 4, 1, 8154, 8205, 0, 26992, 3, 0,
    1, 1, 1, 0, 0, 21,-4,-9, 297, 587, '31/12/2019 10:00',
    4, 69, 208, 214,-535, 532,-586, 1010101010101010101010101010101010101010101010101010101010101010,
    59419
  );
/* INSERT QUERY */
INSERT INTO DUMMYGPS(
  preamble, syncWord, packType, SCID,
  SCTime, timeSource, seqID, OBCTemp,
  battTemp, battVolt, battCurrent,
  chargeCurrent, antDep, dataPending,
  rebootCnt, rails1, rails2, rails3,
  rails4, rails5, rails6, RXTemp, TXTemp,
  PATemp, RXNoiseFloor, seqIDPayload, payloadTimeStamp,
  lat, lon, alt, HDOP, VDOP, PDOP, TDOP,
  hash, CRC
)
VALUES
  (
    10101010101010101010101010101010,
    10101010101010101010101010101010,
    2, 16962, '02/01/2020 10:00', 0, 53875,
    -11, 10, 5, 848, 3445, 0, 11321, 157,
    1, 1, 1, 1, 0, 1,-24,-18,-8, 953, 64737,
    '01/01/2020 10:00',-72,-57, 213,
    -741,-256, 402, 140, 1010101010101010101010101010101010101010101010101010101010101010,
    16364
  );
/* INSERT QUERY */
INSERT INTO DUMMYGPS(
  preamble, syncWord, packType, SCID,
  SCTime, timeSource, seqID, OBCTemp,
  battTemp, battVolt, battCurrent,
  chargeCurrent, antDep, dataPending,
  rebootCnt, rails1, rails2, rails3,
  rails4, rails5, rails6, RXTemp, TXTemp,
  PATemp, RXNoiseFloor, seqIDPayload, payloadTimeStamp,
  lat, lon, alt, HDOP, VDOP, PDOP, TDOP,
  hash, CRC
)
VALUES
  (
    10101010101010101010101010101010,
    10101010101010101010101010101010,
    2, 16962, '03/01/2020 10:00', 0, 5326,
    14, 4, 3, 8124, 6183, 0, 12124, 209, 0,
    1, 0, 1, 1, 0,-24, 9, 17, 170, 51225, '02/01/2020 10:00',
    -55, 173, 155,-648, 821, 991, 986, 1010101010101010101010101010101010101010101010101010101010101010,
    5729
  );
/* INSERT QUERY */
INSERT INTO DUMMYGPS(
  preamble, syncWord, packType, SCID,
  SCTime, timeSource, seqID, OBCTemp,
  battTemp, battVolt, battCurrent,
  chargeCurrent, antDep, dataPending,
  rebootCnt, rails1, rails2, rails3,
  rails4, rails5, rails6, RXTemp, TXTemp,
  PATemp, RXNoiseFloor, seqIDPayload, payloadTimeStamp,
  lat, lon, alt, HDOP, VDOP, PDOP, TDOP,
  hash, CRC
)
VALUES
  (
    10101010101010101010101010101010,
    10101010101010101010101010101010,
    2, 16962, '04/01/2020 10:00', 0, 53345,
    -7, 12, 3, 6443, 2621, 0, 641, 85, 0, 0,
    0, 0, 0, 0, 5,-10,-2, 634, 9762, '03/01/2020 10:00',
    21,-23, 201, 174, 956, 993, 242, 1010101010101010101010101010101010101010101010101010101010101010,
    49624
  );
/* INSERT QUERY */
INSERT INTO DUMMYGPS(
  preamble, syncWord, packType, SCID,
  SCTime, timeSource, seqID, OBCTemp,
  battTemp, battVolt, battCurrent,
  chargeCurrent, antDep, dataPending,
  rebootCnt, rails1, rails2, rails3,
  rails4, rails5, rails6, RXTemp, TXTemp,
  PATemp, RXNoiseFloor, seqIDPayload, payloadTimeStamp,
  lat, lon, alt, HDOP, VDOP, PDOP, TDOP,
  hash, CRC
)
VALUES
  (
    10101010101010101010101010101010,
    10101010101010101010101010101010,
    2, 16962, '05/01/2020 10:00', 0, 60537,
    6,-22, 3, 4388, 6997, 0, 10152, 195,
    0, 0, 0, 1, 0, 0,-12,-6,-17, 854, 50670,
    '04/01/2020 10:00', 78, 80, 179,-38,
    -761, 648,-237, 1010101010101010101010101010101010101010101010101010101010101010,
    29093
  );
/* INSERT QUERY */
INSERT INTO DUMMYGPS(
  preamble, syncWord, packType, SCID,
  SCTime, timeSource, seqID, OBCTemp,
  battTemp, battVolt, battCurrent,
  chargeCurrent, antDep, dataPending,
  rebootCnt, rails1, rails2, rails3,
  rails4, rails5, rails6, RXTemp, TXTemp,
  PATemp, RXNoiseFloor, seqIDPayload, payloadTimeStamp,
  lat, lon, alt, HDOP, VDOP, PDOP, TDOP,
  hash, CRC
)
VALUES
  (
    10101010101010101010101010101010,
    10101010101010101010101010101010,
    2, 16962, '06/01/2020 10:00', 0, 64718,
    17, 14, 2, 8297, 974, 0, 25197, 217, 0,
    1, 1, 1, 0, 1, 7, 20,-12, 716, 11987, '05/01/2020 10:00',
    -26,-66, 156, 903, 727,-930, 289, 1010101010101010101010101010101010101010101010101010101010101010,
    32938
  );
/* INSERT QUERY */
INSERT INTO DUMMYGPS(
  preamble, syncWord, packType, SCID,
  SCTime, timeSource, seqID, OBCTemp,
  battTemp, battVolt, battCurrent,
  chargeCurrent, antDep, dataPending,
  rebootCnt, rails1, rails2, rails3,
  rails4, rails5, rails6, RXTemp, TXTemp,
  PATemp, RXNoiseFloor, seqIDPayload, payloadTimeStamp,
  lat, lon, alt, HDOP, VDOP, PDOP, TDOP,
  hash, CRC
)
VALUES
  (
    10101010101010101010101010101010,
    10101010101010101010101010101010,
    2, 16962, '07/01/2020 10:00', 0, 48666,
    -21, 15, 5, 7540, 3474, 0, 5823, 201,
    1, 1, 0, 0, 1, 1,-13,-25,-14, 449, 64113,
    '06/01/2020 10:00', 64, 66, 188, 842,
    352,-625,-244, 1010101010101010101010101010101010101010101010101010101010101010,
    13078
  );
/* INSERT QUERY */
INSERT INTO DUMMYGPS(
  preamble, syncWord, packType, SCID,
  SCTime, timeSource, seqID, OBCTemp,
  battTemp, battVolt, battCurrent,
  chargeCurrent, antDep, dataPending,
  rebootCnt, rails1, rails2, rails3,
  rails4, rails5, rails6, RXTemp, TXTemp,
  PATemp, RXNoiseFloor, seqIDPayload, payloadTimeStamp,
  lat, lon, alt, HDOP, VDOP, PDOP, TDOP,
  hash, CRC
)
VALUES
  (
    10101010101010101010101010101010,
    10101010101010101010101010101010,
    2, 16962, '08/01/2020 10:00', 0, 44342,
    -5, 2, 1, 5883, 6137, 0, 8351, 178, 0,
    0, 1, 1, 1, 0,-14, 12, 11, 962, 23007,
    '07/01/2020 10:00', 76,-148, 147,
    -810,-349, 497,-833, 1010101010101010101010101010101010101010101010101010101010101010,
    3303
  );
/* INSERT QUERY */
INSERT INTO DUMMYGPS(
  preamble, syncWord, packType, SCID,
  SCTime, timeSource, seqID, OBCTemp,
  battTemp, battVolt, battCurrent,
  chargeCurrent, antDep, dataPending,
  rebootCnt, rails1, rails2, rails3,
  rails4, rails5, rails6, RXTemp, TXTemp,
  PATemp, RXNoiseFloor, seqIDPayload, payloadTimeStamp,
  lat, lon, alt, HDOP, VDOP, PDOP, TDOP,
  hash, CRC
)
VALUES
  (
    10101010101010101010101010101010,
    10101010101010101010101010101010,
    2, 16962, '09/01/2020 10:00', 0, 65008,
    17,-14, 2, 5357, 8016, 0, 26755, 180,
    0, 0, 0, 1, 0, 1, 1,-23, 25, 444, 31074,
    '08/01/2020 10:00', 62, 164, 205,
    -179,-907, 380, 159, 1010101010101010101010101010101010101010101010101010101010101010,
    58294
  );
/* INSERT QUERY */
INSERT INTO DUMMYGPS(
  preamble, syncWord, packType, SCID,
  SCTime, timeSource, seqID, OBCTemp,
  battTemp, battVolt, battCurrent,
  chargeCurrent, antDep, dataPending,
  rebootCnt, rails1, rails2, rails3,
  rails4, rails5, rails6, RXTemp, TXTemp,
  PATemp, RXNoiseFloor, seqIDPayload, payloadTimeStamp,
  lat, lon, alt, HDOP, VDOP, PDOP, TDOP,
  hash, CRC
)
VALUES
  (
    10101010101010101010101010101010,
    10101010101010101010101010101010,
    2, 16962, '10/01/2020 10:00', 0, 30519,
    13,-14, 1, 7324, 9197, 0, 30425, 199,
    0, 1, 0, 0, 1, 0, 17, 6, 12, 529, 26932,
    '09/01/2020 10:00', 89, 146, 115,
    778, 933, 413, 726, 1010101010101010101010101010101010101010101010101010101010101010,
    12311
  );
/* INSERT QUERY */
INSERT INTO DUMMYGPS(
  preamble, syncWord, packType, SCID,
  SCTime, timeSource, seqID, OBCTemp,
  battTemp, battVolt, battCurrent,
  chargeCurrent, antDep, dataPending,
  rebootCnt, rails1, rails2, rails3,
  rails4, rails5, rails6, RXTemp, TXTemp,
  PATemp, RXNoiseFloor, seqIDPayload, payloadTimeStamp,
  lat, lon, alt, HDOP, VDOP, PDOP, TDOP,
  hash, CRC
)
VALUES
  (
    10101010101010101010101010101010,
    10101010101010101010101010101010,
    2, 16962, '11/01/2020 10:00', 0, 63775,
    -4,-11, 3, 3673, 7064, 1, 13714, 198,
    1, 1, 1, 1, 0, 0, 2,-8, 16, 525, 16390,
    '10/01/2020 10:00', 58,-73, 96,-346,
    -63, 9, 647, 1010101010101010101010101010101010101010101010101010101010101010,
    45447
  );
/* INSERT QUERY */
INSERT INTO DUMMYGPS(
  preamble, syncWord, packType, SCID,
  SCTime, timeSource, seqID, OBCTemp,
  battTemp, battVolt, battCurrent,
  chargeCurrent, antDep, dataPending,
  rebootCnt, rails1, rails2, rails3,
  rails4, rails5, rails6, RXTemp, TXTemp,
  PATemp, RXNoiseFloor, seqIDPayload, payloadTimeStamp,
  lat, lon, alt, HDOP, VDOP, PDOP, TDOP,
  hash, CRC
)
VALUES
  (
    10101010101010101010101010101010,
    10101010101010101010101010101010,
    2, 16962, '12/01/2020 10:00', 0, 41313,
    -13,-10, 1, 2917, 1526, 1, 19393, 183,
    0, 0, 1, 0, 0, 1, 23,-14, 8, 583, 30256,
    '11/01/2020 10:00',-14, 128, 246,
    -834,-547,-299, 393, 1010101010101010101010101010101010101010101010101010101010101010,
    14125
  );
/* INSERT QUERY */
INSERT INTO DUMMYGPS(
  preamble, syncWord, packType, SCID,
  SCTime, timeSource, seqID, OBCTemp,
  battTemp, battVolt, battCurrent,
  chargeCurrent, antDep, dataPending,
  rebootCnt, rails1, rails2, rails3,
  rails4, rails5, rails6, RXTemp, TXTemp,
  PATemp, RXNoiseFloor, seqIDPayload, payloadTimeStamp,
  lat, lon, alt, HDOP, VDOP, PDOP, TDOP,
  hash, CRC
)
VALUES
  (
    10101010101010101010101010101010,
    10101010101010101010101010101010,
    2, 16962, '13/01/2020 10:00', 0, 34916,
    0,-11, 3, 494, 7772, 1, 23501, 143, 0,
    1, 0, 1, 0, 0, 7,-10, 22, 130, 63974, '12/01/2020 10:00',
    1, 178, 233, 644, 557, 938,-278, 1010101010101010101010101010101010101010101010101010101010101010,
    58309
  );
/* INSERT QUERY */
INSERT INTO DUMMYGPS(
  preamble, syncWord, packType, SCID,
  SCTime, timeSource, seqID, OBCTemp,
  battTemp, battVolt, battCurrent,
  chargeCurrent, antDep, dataPending,
  rebootCnt, rails1, rails2, rails3,
  rails4, rails5, rails6, RXTemp, TXTemp,
  PATemp, RXNoiseFloor, seqIDPayload, payloadTimeStamp,
  lat, lon, alt, HDOP, VDOP, PDOP, TDOP,
  hash, CRC
)
VALUES
  (
    10101010101010101010101010101010,
    10101010101010101010101010101010,
    2, 16962, '14/01/2020 10:00', 0, 15887,
    -16,-20, 1, 4776, 8602, 1, 28864, 236,
    1, 0, 1, 1, 0, 0, 10,-3,-10, 997, 37820,
    '13/01/2020 10:00', 47, 180, 241,
    -830, 118, 544,-381, 1010101010101010101010101010101010101010101010101010101010101010,
    5114
  );
/* INSERT QUERY */
INSERT INTO DUMMYGPS(
  preamble, syncWord, packType, SCID,
  SCTime, timeSource, seqID, OBCTemp,
  battTemp, battVolt, battCurrent,
  chargeCurrent, antDep, dataPending,
  rebootCnt, rails1, rails2, rails3,
  rails4, rails5, rails6, RXTemp, TXTemp,
  PATemp, RXNoiseFloor, seqIDPayload, payloadTimeStamp,
  lat, lon, alt, HDOP, VDOP, PDOP, TDOP,
  hash, CRC
)
VALUES
  (
    10101010101010101010101010101010,
    10101010101010101010101010101010,
    2, 16962, '15/01/2020 10:00', 0, 16886,
    20, 15, 3, 9400, 2033, 1, 2932, 43, 0,
    0, 0, 0, 1, 0,-23, 0, 8, 427, 21231, '14/01/2020 10:00',
    61, 153, 154, 957, 164,-254,-561, 1010101010101010101010101010101010101010101010101010101010101010,
    45000
  );
/* INSERT QUERY */
INSERT INTO DUMMYGPS(
  preamble, syncWord, packType, SCID,
  SCTime, timeSource, seqID, OBCTemp,
  battTemp, battVolt, battCurrent,
  chargeCurrent, antDep, dataPending,
  rebootCnt, rails1, rails2, rails3,
  rails4, rails5, rails6, RXTemp, TXTemp,
  PATemp, RXNoiseFloor, seqIDPayload, payloadTimeStamp,
  lat, lon, alt, HDOP, VDOP, PDOP, TDOP,
  hash, CRC
)
VALUES
  (
    10101010101010101010101010101010,
    10101010101010101010101010101010,
    2, 16962, '16/01/2020 10:00', 0, 29498,
    6, 12, 5, 3424, 2419, 1, 26718, 134, 1,
    0, 0, 0, 1, 0, 17,-3, 9, 684, 36921, '15/01/2020 10:00',
    68, 84, 114, 689, 335, 981,-810, 1010101010101010101010101010101010101010101010101010101010101010,
    44990
  );
/* INSERT QUERY */
INSERT INTO DUMMYGPS(
  preamble, syncWord, packType, SCID,
  SCTime, timeSource, seqID, OBCTemp,
  battTemp, battVolt, battCurrent,
  chargeCurrent, antDep, dataPending,
  rebootCnt, rails1, rails2, rails3,
  rails4, rails5, rails6, RXTemp, TXTemp,
  PATemp, RXNoiseFloor, seqIDPayload, payloadTimeStamp,
  lat, lon, alt, HDOP, VDOP, PDOP, TDOP,
  hash, CRC
)
VALUES
  (
    10101010101010101010101010101010,
    10101010101010101010101010101010,
    2, 16962, '17/01/2020 10:00', 0, 55514,
    -3,-16, 3, 9319, 9883, 1, 22306, 166,
    0, 1, 0, 1, 1, 0, 4,-20,-2, 821, 24016,
    '16/01/2020 10:00',-51,-140, 101,
    851,-312,-999, 891, 1010101010101010101010101010101010101010101010101010101010101010,
    48425
  );
/* INSERT QUERY */
INSERT INTO DUMMYGPS(
  preamble, syncWord, packType, SCID,
  SCTime, timeSource, seqID, OBCTemp,
  battTemp, battVolt, battCurrent,
  chargeCurrent, antDep, dataPending,
  rebootCnt, rails1, rails2, rails3,
  rails4, rails5, rails6, RXTemp, TXTemp,
  PATemp, RXNoiseFloor, seqIDPayload, payloadTimeStamp,
  lat, lon, alt, HDOP, VDOP, PDOP, TDOP,
  hash, CRC
)
VALUES
  (
    10101010101010101010101010101010,
    10101010101010101010101010101010,
    2, 16962, '18/01/2020 10:00', 0, 34230,
    3,-2, 4, 6027, 7899, 1, 27375, 24, 0,
    0, 1, 0, 0, 1,-17, 18,-5, 964, 42661,
    '17/01/2020 10:00', 54, 162, 107,
    -706,-879, 348, 457, 1010101010101010101010101010101010101010101010101010101010101010,
    1252
  );
/* INSERT QUERY */
INSERT INTO DUMMYGPS(
  preamble, syncWord, packType, SCID,
  SCTime, timeSource, seqID, OBCTemp,
  battTemp, battVolt, battCurrent,
  chargeCurrent, antDep, dataPending,
  rebootCnt, rails1, rails2, rails3,
  rails4, rails5, rails6, RXTemp, TXTemp,
  PATemp, RXNoiseFloor, seqIDPayload, payloadTimeStamp,
  lat, lon, alt, HDOP, VDOP, PDOP, TDOP,
  hash, CRC
)
VALUES
  (
    10101010101010101010101010101010,
    10101010101010101010101010101010,
    2, 16962, '19/01/2020 10:00', 0, 57277,
    -6, 21, 3, 7080, 6305, 1, 13411, 130,
    0, 1, 1, 1, 1, 0,-17, 5,-24, 506, 29980,
    '18/01/2020 10:00',-88,-56, 101,
    -407,-240,-19,-546, 1010101010101010101010101010101010101010101010101010101010101010,
    37294
  );
/* INSERT QUERY */
INSERT INTO DUMMYGPS(
  preamble, syncWord, packType, SCID,
  SCTime, timeSource, seqID, OBCTemp,
  battTemp, battVolt, battCurrent,
  chargeCurrent, antDep, dataPending,
  rebootCnt, rails1, rails2, rails3,
  rails4, rails5, rails6, RXTemp, TXTemp,
  PATemp, RXNoiseFloor, seqIDPayload, payloadTimeStamp,
  lat, lon, alt, HDOP, VDOP, PDOP, TDOP,
  hash, CRC
)
VALUES
  (
    10101010101010101010101010101010,
    10101010101010101010101010101010,
    2, 16962, '20/01/2020 10:00', 0, 157,
    -16, 24, 2, 2403, 5281, 1, 13659, 86,
    0, 0, 0, 1, 1, 0, 24,-3,-2, 748, 58671,
    '19/01/2020 10:00',-14, 23, 151,
    710, 707,-125, 240, 1010101010101010101010101010101010101010101010101010101010101010,
    19177
  );
/* INSERT QUERY */
INSERT INTO DUMMYGPS(
  preamble, syncWord, packType, SCID,
  SCTime, timeSource, seqID, OBCTemp,
  battTemp, battVolt, battCurrent,
  chargeCurrent, antDep, dataPending,
  rebootCnt, rails1, rails2, rails3,
  rails4, rails5, rails6, RXTemp, TXTemp,
  PATemp, RXNoiseFloor, seqIDPayload, payloadTimeStamp,
  lat, lon, alt, HDOP, VDOP, PDOP, TDOP,
  hash, CRC
)
VALUES
  (
    10101010101010101010101010101010,
    10101010101010101010101010101010,
    2, 16962, '21/01/2020 10:00', 0, 35232,
    -18, 23, 4, 8692, 1121, 1, 16979, 223,
    0, 1, 0, 0, 1, 0, 21, 24,-2, 231, 63021,
    '20/01/2020 10:00', 27,-135, 146,
    -546, 969,-403,-222, 1010101010101010101010101010101010101010101010101010101010101010,
    51594
  );
/* INSERT QUERY */
INSERT INTO DUMMYGPS(
  preamble, syncWord, packType, SCID,
  SCTime, timeSource, seqID, OBCTemp,
  battTemp, battVolt, battCurrent,
  chargeCurrent, antDep, dataPending,
  rebootCnt, rails1, rails2, rails3,
  rails4, rails5, rails6, RXTemp, TXTemp,
  PATemp, RXNoiseFloor, seqIDPayload, payloadTimeStamp,
  lat, lon, alt, HDOP, VDOP, PDOP, TDOP,
  hash, CRC
)
VALUES
  (
    10101010101010101010101010101010,
    10101010101010101010101010101010,
    2, 16962, '22/01/2020 10:00', 0, 28957,
    -14, 10, 1, 3389, 5950, 1, 26494, 34,
    0, 1, 1, 1, 1, 1,-12, 3, 23, 378, 32211,
    '21/01/2020 10:00', 42,-99, 176,
    602,-288, 94, 804, 1010101010101010101010101010101010101010101010101010101010101010,
    37321
  );
/* INSERT QUERY */
INSERT INTO DUMMYGPS(
  preamble, syncWord, packType, SCID,
  SCTime, timeSource, seqID, OBCTemp,
  battTemp, battVolt, battCurrent,
  chargeCurrent, antDep, dataPending,
  rebootCnt, rails1, rails2, rails3,
  rails4, rails5, rails6, RXTemp, TXTemp,
  PATemp, RXNoiseFloor, seqIDPayload, payloadTimeStamp,
  lat, lon, alt, HDOP, VDOP, PDOP, TDOP,
  hash, CRC
)
VALUES
  (
    10101010101010101010101010101010,
    10101010101010101010101010101010,
    2, 16962, '23/01/2020 10:00', 0, 7127,
    -17, 13, 2, 8747, 6893, 1, 16893, 67,
    0, 0, 1, 0, 0, 0,-8, 8,-20, 406, 47687,
    '22/01/2020 10:00', 5, 165, 188,-810,
    -369,-698,-310, 1010101010101010101010101010101010101010101010101010101010101010,
    7033
  );
/* INSERT QUERY */
INSERT INTO DUMMYGPS(
  preamble, syncWord, packType, SCID,
  SCTime, timeSource, seqID, OBCTemp,
  battTemp, battVolt, battCurrent,
  chargeCurrent, antDep, dataPending,
  rebootCnt, rails1, rails2, rails3,
  rails4, rails5, rails6, RXTemp, TXTemp,
  PATemp, RXNoiseFloor, seqIDPayload, payloadTimeStamp,
  lat, lon, alt, HDOP, VDOP, PDOP, TDOP,
  hash, CRC
)
VALUES
  (
    10101010101010101010101010101010,
    10101010101010101010101010101010,
    2, 16962, '24/01/2020 10:00', 0, 23398,
    -25,-14, 4, 6155, 4424, 1, 6299, 161,
    0, 1, 0, 0, 0, 0, 14, 21, 5, 556, 46521,
    '23/01/2020 10:00', 3,-126, 84,-32,
    420, 73, 589, 1010101010101010101010101010101010101010101010101010101010101010,
    37884
  );
/* INSERT QUERY */
INSERT INTO DUMMYGPS(
  preamble, syncWord, packType, SCID,
  SCTime, timeSource, seqID, OBCTemp,
  battTemp, battVolt, battCurrent,
  chargeCurrent, antDep, dataPending,
  rebootCnt, rails1, rails2, rails3,
  rails4, rails5, rails6, RXTemp, TXTemp,
  PATemp, RXNoiseFloor, seqIDPayload, payloadTimeStamp,
  lat, lon, alt, HDOP, VDOP, PDOP, TDOP,
  hash, CRC
)
VALUES
  (
    10101010101010101010101010101010,
    10101010101010101010101010101010,
    2, 16962, '25/01/2020 10:00', 0, 11522,
    0,-11, 5, 5911, 4288, 1, 2068, 157, 0,
    1, 1, 1, 1, 0, 23,-25, 20, 458, 9960, '24/01/2020 10:00',
    -75,-39, 111,-512,-114, 293, 346,
    1010101010101010101010101010101010101010101010101010101010101010,
    39778
  );
/* INSERT QUERY */
INSERT INTO DUMMYGPS(
  preamble, syncWord, packType, SCID,
  SCTime, timeSource, seqID, OBCTemp,
  battTemp, battVolt, battCurrent,
  chargeCurrent, antDep, dataPending,
  rebootCnt, rails1, rails2, rails3,
  rails4, rails5, rails6, RXTemp, TXTemp,
  PATemp, RXNoiseFloor, seqIDPayload, payloadTimeStamp,
  lat, lon, alt, HDOP, VDOP, PDOP, TDOP,
  hash, CRC
)
VALUES
  (
    10101010101010101010101010101010,
    10101010101010101010101010101010,
    2, 16962, '26/01/2020 10:00', 0, 7882,
    2,-8, 1, 3678, 3140, 1, 20843, 104, 1,
    0, 1, 0, 0, 1, 8,-20, 12, 657, 55980, '25/01/2020 10:00',
    65,-30, 154, 509, 173,-650,-65, 1010101010101010101010101010101010101010101010101010101010101010,
    17417
  );
/* INSERT QUERY */
INSERT INTO DUMMYGPS(
  preamble, syncWord, packType, SCID,
  SCTime, timeSource, seqID, OBCTemp,
  battTemp, battVolt, battCurrent,
  chargeCurrent, antDep, dataPending,
  rebootCnt, rails1, rails2, rails3,
  rails4, rails5, rails6, RXTemp, TXTemp,
  PATemp, RXNoiseFloor, seqIDPayload, payloadTimeStamp,
  lat, lon, alt, HDOP, VDOP, PDOP, TDOP,
  hash, CRC
)
VALUES
  (
    10101010101010101010101010101010,
    10101010101010101010101010101010,
    2, 16962, '27/01/2020 10:00', 0, 58997,
    12, 4, 1, 3049, 9529, 1, 7521, 54, 0, 0,
    1, 1, 0, 0, 14,-22,-17, 615, 44403, '26/01/2020 10:00',
    -23,-106, 232, 606,-870,-770, 215,
    1010101010101010101010101010101010101010101010101010101010101010,
    24836
  );
/* INSERT QUERY */
INSERT INTO DUMMYGPS(
  preamble, syncWord, packType, SCID,
  SCTime, timeSource, seqID, OBCTemp,
  battTemp, battVolt, battCurrent,
  chargeCurrent, antDep, dataPending,
  rebootCnt, rails1, rails2, rails3,
  rails4, rails5, rails6, RXTemp, TXTemp,
  PATemp, RXNoiseFloor, seqIDPayload, payloadTimeStamp,
  lat, lon, alt, HDOP, VDOP, PDOP, TDOP,
  hash, CRC
)
VALUES
  (
    10101010101010101010101010101010,
    10101010101010101010101010101010,
    2, 16962, '28/01/2020 10:00', 0, 6576,
    -7,-23, 5, 9750, 3607, 1, 26430, 53,
    1, 1, 1, 0, 1, 1, 11,-1,-14, 56, 17367,
    '27/01/2020 10:00', 5,-87, 178,-26,
    228, 597,-940, 1010101010101010101010101010101010101010101010101010101010101010,
    62389
  );
/* INSERT QUERY */
INSERT INTO DUMMYGPS(
  preamble, syncWord, packType, SCID,
  SCTime, timeSource, seqID, OBCTemp,
  battTemp, battVolt, battCurrent,
  chargeCurrent, antDep, dataPending,
  rebootCnt, rails1, rails2, rails3,
  rails4, rails5, rails6, RXTemp, TXTemp,
  PATemp, RXNoiseFloor, seqIDPayload, payloadTimeStamp,
  lat, lon, alt, HDOP, VDOP, PDOP, TDOP,
  hash, CRC
)
VALUES
  (
    10101010101010101010101010101010,
    10101010101010101010101010101010,
    2, 16962, '29/01/2020 10:00', 0, 9033,
    15, 11, 3, 5379, 3390, 1, 28063, 110,
    1, 1, 1, 1, 0, 1,-15, 14, 6, 978, 12601,
    '28/01/2020 10:00', 76,-7, 206, 160,
    -918,-622,-940, 1010101010101010101010101010101010101010101010101010101010101010,
    13198
  );
/* INSERT QUERY */
INSERT INTO DUMMYGPS(
  preamble, syncWord, packType, SCID,
  SCTime, timeSource, seqID, OBCTemp,
  battTemp, battVolt, battCurrent,
  chargeCurrent, antDep, dataPending,
  rebootCnt, rails1, rails2, rails3,
  rails4, rails5, rails6, RXTemp, TXTemp,
  PATemp, RXNoiseFloor, seqIDPayload, payloadTimeStamp,
  lat, lon, alt, HDOP, VDOP, PDOP, TDOP,
  hash, CRC
)
VALUES
  (
    10101010101010101010101010101010,
    10101010101010101010101010101010,
    2, 16962, '30/01/2020 10:00', 0, 55278,
    -1,-8, 4, 8847, 6968, 1, 3018, 86, 0,
    0, 1, 0, 0, 1, 22,-8,-9, 926, 40625, '29/01/2020 10:00',
    -29,-84, 191, 807, 597,-680,-903,
    1010101010101010101010101010101010101010101010101010101010101010,
    6790
  );
/* INSERT QUERY */
INSERT INTO DUMMYGPS(
  preamble, syncWord, packType, SCID,
  SCTime, timeSource, seqID, OBCTemp,
  battTemp, battVolt, battCurrent,
  chargeCurrent, antDep, dataPending,
  rebootCnt, rails1, rails2, rails3,
  rails4, rails5, rails6, RXTemp, TXTemp,
  PATemp, RXNoiseFloor, seqIDPayload, payloadTimeStamp,
  lat, lon, alt, HDOP, VDOP, PDOP, TDOP,
  hash, CRC
)
VALUES
  (
    10101010101010101010101010101010,
    10101010101010101010101010101010,
    2, 16962, '31/01/2020 10:00', 0, 24170,
    -10, 10, 5, 4113, 368, 1, 9938, 127, 0,
    1, 1, 0, 0, 1, 23,-2,-11, 705, 46511,
    '30/01/2020 10:00',-22,-178, 190,
    564, 715, 291,-382, 1010101010101010101010101010101010101010101010101010101010101010,
    18447
  );
/* INSERT QUERY */
INSERT INTO DUMMYGPS(
  preamble, syncWord, packType, SCID,
  SCTime, timeSource, seqID, OBCTemp,
  battTemp, battVolt, battCurrent,
  chargeCurrent, antDep, dataPending,
  rebootCnt, rails1, rails2, rails3,
  rails4, rails5, rails6, RXTemp, TXTemp,
  PATemp, RXNoiseFloor, seqIDPayload, payloadTimeStamp,
  lat, lon, alt, HDOP, VDOP, PDOP, TDOP,
  hash, CRC
)
VALUES
  (
    10101010101010101010101010101010,
    10101010101010101010101010101010,
    2, 16962, '01/02/2020 10:00', 0, 47516,
    9,-20, 3, 3704, 5366, 1, 26804, 19, 1,
    1, 0, 1, 1, 0, 8,-18, 19, 205, 26954, '31/01/2020 10:00',
    -4, 47, 249,-836,-731,-263,-999,
    1010101010101010101010101010101010101010101010101010101010101010,
    57806
  );
/* INSERT QUERY */
INSERT INTO DUMMYGPS(
  preamble, syncWord, packType, SCID,
  SCTime, timeSource, seqID, OBCTemp,
  battTemp, battVolt, battCurrent,
  chargeCurrent, antDep, dataPending,
  rebootCnt, rails1, rails2, rails3,
  rails4, rails5, rails6, RXTemp, TXTemp,
  PATemp, RXNoiseFloor, seqIDPayload, payloadTimeStamp,
  lat, lon, alt, HDOP, VDOP, PDOP, TDOP,
  hash, CRC
)
VALUES
  (
    10101010101010101010101010101010,
    10101010101010101010101010101010,
    2, 16962, '02/02/2020 10:00', 0, 16499,
    -12,-23, 5, 3127, 5818, 1, 5853, 220,
    0, 1, 1, 0, 0, 1, 2, 21, 7, 721, 65003, '01/02/2020 10:00',
    -10,-58, 221, 614,-656, 725, 876, 1010101010101010101010101010101010101010101010101010101010101010,
    44368
  );
/* INSERT QUERY */
INSERT INTO DUMMYGPS(
  preamble, syncWord, packType, SCID,
  SCTime, timeSource, seqID, OBCTemp,
  battTemp, battVolt, battCurrent,
  chargeCurrent, antDep, dataPending,
  rebootCnt, rails1, rails2, rails3,
  rails4, rails5, rails6, RXTemp, TXTemp,
  PATemp, RXNoiseFloor, seqIDPayload, payloadTimeStamp,
  lat, lon, alt, HDOP, VDOP, PDOP, TDOP,
  hash, CRC
)
VALUES
  (
    10101010101010101010101010101010,
    10101010101010101010101010101010,
    2, 16962, '03/02/2020 10:00', 0, 9417,
    -18,-7, 2, 7012, 3600, 1, 16225, 251,
    1, 1, 0, 1, 1, 1, 2,-2,-15, 783, 44881,
    '02/02/2020 10:00',-55, 156, 244,
    -901,-604, 610, 277, 1010101010101010101010101010101010101010101010101010101010101010,
    61857
  );
/* INSERT QUERY */
INSERT INTO DUMMYGPS(
  preamble, syncWord, packType, SCID,
  SCTime, timeSource, seqID, OBCTemp,
  battTemp, battVolt, battCurrent,
  chargeCurrent, antDep, dataPending,
  rebootCnt, rails1, rails2, rails3,
  rails4, rails5, rails6, RXTemp, TXTemp,
  PATemp, RXNoiseFloor, seqIDPayload, payloadTimeStamp,
  lat, lon, alt, HDOP, VDOP, PDOP, TDOP,
  hash, CRC
)
VALUES
  (
    10101010101010101010101010101010,
    10101010101010101010101010101010,
    2, 16962, '04/02/2020 10:00', 1, 56780,
    1, 15, 1, 9484, 8163, 1, 24974, 20, 0,
    0, 1, 0, 0, 1,-17,-11, 15, 860, 17819,
    '03/02/2020 10:00',-77,-37, 120,
    457, 24, 261, 781, 1010101010101010101010101010101010101010101010101010101010101010,
    18299
  );
/* INSERT QUERY */
INSERT INTO DUMMYGPS(
  preamble, syncWord, packType, SCID,
  SCTime, timeSource, seqID, OBCTemp,
  battTemp, battVolt, battCurrent,
  chargeCurrent, antDep, dataPending,
  rebootCnt, rails1, rails2, rails3,
  rails4, rails5, rails6, RXTemp, TXTemp,
  PATemp, RXNoiseFloor, seqIDPayload, payloadTimeStamp,
  lat, lon, alt, HDOP, VDOP, PDOP, TDOP,
  hash, CRC
)
VALUES
  (
    10101010101010101010101010101010,
    10101010101010101010101010101010,
    2, 16962, '05/02/2020 10:00', 1, 23038,
    9,-8, 2, 5070, 6167, 1, 17553, 202, 0,
    1, 1, 0, 1, 0,-24, 5, 25, 756, 50493, '04/02/2020 10:00',
    -27,-134, 217, 598, 135, 921,-946,
    1010101010101010101010101010101010101010101010101010101010101010,
    29743
  );
/* INSERT QUERY */
INSERT INTO DUMMYGPS(
  preamble, syncWord, packType, SCID,
  SCTime, timeSource, seqID, OBCTemp,
  battTemp, battVolt, battCurrent,
  chargeCurrent, antDep, dataPending,
  rebootCnt, rails1, rails2, rails3,
  rails4, rails5, rails6, RXTemp, TXTemp,
  PATemp, RXNoiseFloor, seqIDPayload, payloadTimeStamp,
  lat, lon, alt, HDOP, VDOP, PDOP, TDOP,
  hash, CRC
)
VALUES
  (
    10101010101010101010101010101010,
    10101010101010101010101010101010,
    2, 16962, '06/02/2020 10:00', 1, 19976,
    -11, 10, 4, 5543, 1168, 1, 26666, 110,
    1, 0, 0, 0, 1, 0,-8, 0, 10, 361, 12247,
    '05/02/2020 10:00', 69,-74, 122,
    -231,-241, 935, 25, 1010101010101010101010101010101010101010101010101010101010101010,
    19315
  );
/* INSERT QUERY */
INSERT INTO DUMMYGPS(
  preamble, syncWord, packType, SCID,
  SCTime, timeSource, seqID, OBCTemp,
  battTemp, battVolt, battCurrent,
  chargeCurrent, antDep, dataPending,
  rebootCnt, rails1, rails2, rails3,
  rails4, rails5, rails6, RXTemp, TXTemp,
  PATemp, RXNoiseFloor, seqIDPayload, payloadTimeStamp,
  lat, lon, alt, HDOP, VDOP, PDOP, TDOP,
  hash, CRC
)
VALUES
  (
    10101010101010101010101010101010,
    10101010101010101010101010101010,
    2, 16962, '07/02/2020 10:00', 1, 54046,
    -3,-18, 0, 5857, 5805, 1, 15074, 234,
    1, 1, 0, 0, 0, 0, 9, 7, 15, 22, 12463, '06/02/2020 10:00',
    48,-7, 120, 74,-416, 225,-326, 1010101010101010101010101010101010101010101010101010101010101010,
    63647
  );
/* INSERT QUERY */
INSERT INTO DUMMYGPS(
  preamble, syncWord, packType, SCID,
  SCTime, timeSource, seqID, OBCTemp,
  battTemp, battVolt, battCurrent,
  chargeCurrent, antDep, dataPending,
  rebootCnt, rails1, rails2, rails3,
  rails4, rails5, rails6, RXTemp, TXTemp,
  PATemp, RXNoiseFloor, seqIDPayload, payloadTimeStamp,
  lat, lon, alt, HDOP, VDOP, PDOP, TDOP,
  hash, CRC
)
VALUES
  (
    10101010101010101010101010101010,
    10101010101010101010101010101010,
    2, 16962, '08/02/2020 10:00', 1, 19442,
    21, 19, 4, 678, 1301, 1, 12115, 110, 0,
    0, 1, 0, 0, 0, 4, 22,-8, 688, 1006, '07/02/2020 10:00',
    -18,-53, 113, 69,-804, 423,-945, 1010101010101010101010101010101010101010101010101010101010101010,
    13698
  );
/* INSERT QUERY */
INSERT INTO DUMMYGPS(
  preamble, syncWord, packType, SCID,
  SCTime, timeSource, seqID, OBCTemp,
  battTemp, battVolt, battCurrent,
  chargeCurrent, antDep, dataPending,
  rebootCnt, rails1, rails2, rails3,
  rails4, rails5, rails6, RXTemp, TXTemp,
  PATemp, RXNoiseFloor, seqIDPayload, payloadTimeStamp,
  lat, lon, alt, HDOP, VDOP, PDOP, TDOP,
  hash, CRC
)
VALUES
  (
    10101010101010101010101010101010,
    10101010101010101010101010101010,
    2, 16962, '09/02/2020 10:00', 1, 63524,
    1, 25, 4, 4613, 1114, 1, 11781, 181, 0,
    1, 0, 1, 0, 1,-15, 2, 21, 429, 57999, '08/02/2020 10:00',
    73, 171, 122, 831, 670,-424,-259, 1010101010101010101010101010101010101010101010101010101010101010,
    64319
  );
/* INSERT QUERY */
INSERT INTO DUMMYGPS(
  preamble, syncWord, packType, SCID,
  SCTime, timeSource, seqID, OBCTemp,
  battTemp, battVolt, battCurrent,
  chargeCurrent, antDep, dataPending,
  rebootCnt, rails1, rails2, rails3,
  rails4, rails5, rails6, RXTemp, TXTemp,
  PATemp, RXNoiseFloor, seqIDPayload, payloadTimeStamp,
  lat, lon, alt, HDOP, VDOP, PDOP, TDOP,
  hash, CRC
)
VALUES
  (
    10101010101010101010101010101010,
    10101010101010101010101010101010,
    2, 16962, '10/02/2020 10:00', 1, 15105,
    15,-19, 5, 8243, 7574, 1, 16914, 121,
    0, 0, 0, 0, 0, 0,-5,-25,-13, 305, 25165,
    '09/02/2020 10:00',-62, 26, 162,
    -698, 630, 752,-959, 1010101010101010101010101010101010101010101010101010101010101010,
    54291
  );
/* INSERT QUERY */
INSERT INTO DUMMYGPS(
  preamble, syncWord, packType, SCID,
  SCTime, timeSource, seqID, OBCTemp,
  battTemp, battVolt, battCurrent,
  chargeCurrent, antDep, dataPending,
  rebootCnt, rails1, rails2, rails3,
  rails4, rails5, rails6, RXTemp, TXTemp,
  PATemp, RXNoiseFloor, seqIDPayload, payloadTimeStamp,
  lat, lon, alt, HDOP, VDOP, PDOP, TDOP,
  hash, CRC
)
VALUES
  (
    10101010101010101010101010101010,
    10101010101010101010101010101010,
    2, 16962, '11/02/2020 10:00', 1, 23414,
    19,-3, 0, 5607, 9820, 1, 994, 29, 1, 1,
    1, 0, 0, 1, 8,-16, 1, 3, 50504, '10/02/2020 10:00',
    33,-139, 163, 747, 96, 62,-745, 1010101010101010101010101010101010101010101010101010101010101010,
    7399
  );
/* INSERT QUERY */
INSERT INTO DUMMYGPS(
  preamble, syncWord, packType, SCID,
  SCTime, timeSource, seqID, OBCTemp,
  battTemp, battVolt, battCurrent,
  chargeCurrent, antDep, dataPending,
  rebootCnt, rails1, rails2, rails3,
  rails4, rails5, rails6, RXTemp, TXTemp,
  PATemp, RXNoiseFloor, seqIDPayload, payloadTimeStamp,
  lat, lon, alt, HDOP, VDOP, PDOP, TDOP,
  hash, CRC
)
VALUES
  (
    10101010101010101010101010101010,
    10101010101010101010101010101010,
    2, 16962, '12/02/2020 10:00', 1, 52922,
    20, 8, 5, 7710, 588, 1, 21480, 29, 1, 1,
    1, 1, 1, 0,-15, 16,-18, 542, 64953, '11/02/2020 10:00',
    -43,-158, 155,-523, 968, 845, 833,
    1010101010101010101010101010101010101010101010101010101010101010,
    47026
  );
/* INSERT QUERY */
INSERT INTO DUMMYGPS(
  preamble, syncWord, packType, SCID,
  SCTime, timeSource, seqID, OBCTemp,
  battTemp, battVolt, battCurrent,
  chargeCurrent, antDep, dataPending,
  rebootCnt, rails1, rails2, rails3,
  rails4, rails5, rails6, RXTemp, TXTemp,
  PATemp, RXNoiseFloor, seqIDPayload, payloadTimeStamp,
  lat, lon, alt, HDOP, VDOP, PDOP, TDOP,
  hash, CRC
)
VALUES
  (
    10101010101010101010101010101010,
    10101010101010101010101010101010,
    2, 16962, '13/02/2020 10:00', 1, 18254,
    1,-6, 4, 7030, 6044, 1, 19504, 0, 0, 0,
    1, 1, 1, 1, 25,-1, 17, 995, 51514, '12/02/2020 10:00',
    -57,-107, 119, 184,-853,-308,-314,
    1010101010101010101010101010101010101010101010101010101010101010,
    53722
  );
/* INSERT QUERY */
INSERT INTO DUMMYGPS(
  preamble, syncWord, packType, SCID,
  SCTime, timeSource, seqID, OBCTemp,
  battTemp, battVolt, battCurrent,
  chargeCurrent, antDep, dataPending,
  rebootCnt, rails1, rails2, rails3,
  rails4, rails5, rails6, RXTemp, TXTemp,
  PATemp, RXNoiseFloor, seqIDPayload, payloadTimeStamp,
  lat, lon, alt, HDOP, VDOP, PDOP, TDOP,
  hash, CRC
)
VALUES
  (
    10101010101010101010101010101010,
    10101010101010101010101010101010,
    2, 16962, '14/02/2020 10:00', 1, 7899,
    -1, 8, 3, 1104, 7329, 1, 5873, 243, 0,
    0, 0, 0, 1, 1,-6,-10, 15, 161, 29611,
    '13/02/2020 10:00', 7,-36, 90,-634,
    494, 87, 553, 1010101010101010101010101010101010101010101010101010101010101010,
    46920
  );
/* INSERT QUERY */
INSERT INTO DUMMYGPS(
  preamble, syncWord, packType, SCID,
  SCTime, timeSource, seqID, OBCTemp,
  battTemp, battVolt, battCurrent,
  chargeCurrent, antDep, dataPending,
  rebootCnt, rails1, rails2, rails3,
  rails4, rails5, rails6, RXTemp, TXTemp,
  PATemp, RXNoiseFloor, seqIDPayload, payloadTimeStamp,
  lat, lon, alt, HDOP, VDOP, PDOP, TDOP,
  hash, CRC
)
VALUES
  (
    10101010101010101010101010101010,
    10101010101010101010101010101010,
    2, 16962, '15/02/2020 10:00', 1, 4546,
    0, 8, 2, 1130, 3442, 1, 17971, 149, 0,
    1, 1, 1, 0, 0, 5,-14,-23, 415, 16008,
    '14/02/2020 10:00',-62, 82, 224,
    -621, 505,-914,-755, 1010101010101010101010101010101010101010101010101010101010101010,
    51829
  );
/* INSERT QUERY */
INSERT INTO DUMMYGPS(
  preamble, syncWord, packType, SCID,
  SCTime, timeSource, seqID, OBCTemp,
  battTemp, battVolt, battCurrent,
  chargeCurrent, antDep, dataPending,
  rebootCnt, rails1, rails2, rails3,
  rails4, rails5, rails6, RXTemp, TXTemp,
  PATemp, RXNoiseFloor, seqIDPayload, payloadTimeStamp,
  lat, lon, alt, HDOP, VDOP, PDOP, TDOP,
  hash, CRC
)
VALUES
  (
    10101010101010101010101010101010,
    10101010101010101010101010101010,
    2, 16962, '16/02/2020 10:00', 1, 34282,
    14,-24, 3, 615, 7103, 1, 24834, 228,
    1, 0, 0, 1, 0, 0,-25,-8, 10, 497, 8669,
    '15/02/2020 10:00',-23, 34, 92,-970,
    -783,-865,-208, 1010101010101010101010101010101010101010101010101010101010101010,
    2815
  );
/* INSERT QUERY */
INSERT INTO DUMMYGPS(
  preamble, syncWord, packType, SCID,
  SCTime, timeSource, seqID, OBCTemp,
  battTemp, battVolt, battCurrent,
  chargeCurrent, antDep, dataPending,
  rebootCnt, rails1, rails2, rails3,
  rails4, rails5, rails6, RXTemp, TXTemp,
  PATemp, RXNoiseFloor, seqIDPayload, payloadTimeStamp,
  lat, lon, alt, HDOP, VDOP, PDOP, TDOP,
  hash, CRC
)
VALUES
  (
    10101010101010101010101010101010,
    10101010101010101010101010101010,
    2, 16962, '17/02/2020 10:00', 1, 27826,
    7, 10, 2, 2701, 7655, 1, 7220, 8, 0, 0,
    0, 1, 0, 0,-25,-17,-22, 258, 51981,
    '16/02/2020 10:00',-4,-20, 168,
    204, 265, 868, 64, 1010101010101010101010101010101010101010101010101010101010101010,
    58024
  );
/* INSERT QUERY */
INSERT INTO DUMMYGPS(
  preamble, syncWord, packType, SCID,
  SCTime, timeSource, seqID, OBCTemp,
  battTemp, battVolt, battCurrent,
  chargeCurrent, antDep, dataPending,
  rebootCnt, rails1, rails2, rails3,
  rails4, rails5, rails6, RXTemp, TXTemp,
  PATemp, RXNoiseFloor, seqIDPayload, payloadTimeStamp,
  lat, lon, alt, HDOP, VDOP, PDOP, TDOP,
  hash, CRC
)
VALUES
  (
    10101010101010101010101010101010,
    10101010101010101010101010101010,
    2, 16962, '18/02/2020 10:00', 1, 58606,
    9, 23, 1, 8229, 7842, 1, 14432, 99, 0,
    1, 0, 1, 0, 0,-18,-5,-5, 780, 27727,
    '17/02/2020 10:00', 49,-98, 84, 422,
    -936,-999,-286, 1010101010101010101010101010101010101010101010101010101010101010,
    57510
  );
/* INSERT QUERY */
INSERT INTO DUMMYGPS(
  preamble, syncWord, packType, SCID,
  SCTime, timeSource, seqID, OBCTemp,
  battTemp, battVolt, battCurrent,
  chargeCurrent, antDep, dataPending,
  rebootCnt, rails1, rails2, rails3,
  rails4, rails5, rails6, RXTemp, TXTemp,
  PATemp, RXNoiseFloor, seqIDPayload, payloadTimeStamp,
  lat, lon, alt, HDOP, VDOP, PDOP, TDOP,
  hash, CRC
)
VALUES
  (
    10101010101010101010101010101010,
    10101010101010101010101010101010,
    2, 16962, '19/02/2020 10:00', 1, 62510,
    6,-21, 3, 8466, 6376, 1, 30205, 124,
    1, 1, 0, 0, 1, 1, 16, 17,-25, 230, 16708,
    '18/02/2020 10:00', 77, 54, 189,-616,
    665,-343,-408, 1010101010101010101010101010101010101010101010101010101010101010,
    15711
  );
/* INSERT QUERY */
INSERT INTO DUMMYGPS(
  preamble, syncWord, packType, SCID,
  SCTime, timeSource, seqID, OBCTemp,
  battTemp, battVolt, battCurrent,
  chargeCurrent, antDep, dataPending,
  rebootCnt, rails1, rails2, rails3,
  rails4, rails5, rails6, RXTemp, TXTemp,
  PATemp, RXNoiseFloor, seqIDPayload, payloadTimeStamp,
  lat, lon, alt, HDOP, VDOP, PDOP, TDOP,
  hash, CRC
)
VALUES
  (
    10101010101010101010101010101010,
    10101010101010101010101010101010,
    2, 16962, '20/02/2020 10:00', 1, 41455,
    19,-5, 3, 723, 9163, 1, 18585, 148, 1,
    0, 1, 1, 1, 1, 3,-21,-8, 450, 40571, '19/02/2020 10:00',
    47,-120, 110,-976,-438, 999,-880,
    1010101010101010101010101010101010101010101010101010101010101010,
    49412
  );
/* INSERT QUERY */
INSERT INTO DUMMYGPS(
  preamble, syncWord, packType, SCID,
  SCTime, timeSource, seqID, OBCTemp,
  battTemp, battVolt, battCurrent,
  chargeCurrent, antDep, dataPending,
  rebootCnt, rails1, rails2, rails3,
  rails4, rails5, rails6, RXTemp, TXTemp,
  PATemp, RXNoiseFloor, seqIDPayload, payloadTimeStamp,
  lat, lon, alt, HDOP, VDOP, PDOP, TDOP,
  hash, CRC
)
VALUES
  (
    10101010101010101010101010101010,
    10101010101010101010101010101010,
    2, 16962, '21/02/2020 10:00', 1, 8433,
    -14,-5, 4, 3389, 5710, 1, 18532, 209,
    1, 1, 0, 0, 1, 0,-10,-19, 5, 786, 25025,
    '20/02/2020 10:00', 78, 7, 209, 305,
    876, 861,-930, 1010101010101010101010101010101010101010101010101010101010101010,
    27277
  );
/* INSERT QUERY */
INSERT INTO DUMMYGPS(
  preamble, syncWord, packType, SCID,
  SCTime, timeSource, seqID, OBCTemp,
  battTemp, battVolt, battCurrent,
  chargeCurrent, antDep, dataPending,
  rebootCnt, rails1, rails2, rails3,
  rails4, rails5, rails6, RXTemp, TXTemp,
  PATemp, RXNoiseFloor, seqIDPayload, payloadTimeStamp,
  lat, lon, alt, HDOP, VDOP, PDOP, TDOP,
  hash, CRC
)
VALUES
  (
    10101010101010101010101010101010,
    10101010101010101010101010101010,
    2, 16962, '22/02/2020 10:00', 1, 53566,
    -24, 10, 3, 889, 5018, 1, 14596, 36, 1,
    1, 1, 1, 1, 1, 6, 7,-15, 614, 26143, '21/02/2020 10:00',
    36,-53, 135, 150, 457, 375, 759, 1010101010101010101010101010101010101010101010101010101010101010,
    54146
  );
/* INSERT QUERY */
INSERT INTO DUMMYGPS(
  preamble, syncWord, packType, SCID,
  SCTime, timeSource, seqID, OBCTemp,
  battTemp, battVolt, battCurrent,
  chargeCurrent, antDep, dataPending,
  rebootCnt, rails1, rails2, rails3,
  rails4, rails5, rails6, RXTemp, TXTemp,
  PATemp, RXNoiseFloor, seqIDPayload, payloadTimeStamp,
  lat, lon, alt, HDOP, VDOP, PDOP, TDOP,
  hash, CRC
)
VALUES
  (
    10101010101010101010101010101010,
    10101010101010101010101010101010,
    2, 16962, '23/02/2020 10:00', 1, 30081,
    -14,-12, 3, 3082, 8770, 1, 27684, 125,
    1, 1, 1, 0, 0, 1,-23, 11,-8, 649, 8539,
    '22/02/2020 10:00', 64, 147, 102,
    -168,-809,-40, 965, 1010101010101010101010101010101010101010101010101010101010101010,
    38870
  );
/* INSERT QUERY */
INSERT INTO DUMMYGPS(
  preamble, syncWord, packType, SCID,
  SCTime, timeSource, seqID, OBCTemp,
  battTemp, battVolt, battCurrent,
  chargeCurrent, antDep, dataPending,
  rebootCnt, rails1, rails2, rails3,
  rails4, rails5, rails6, RXTemp, TXTemp,
  PATemp, RXNoiseFloor, seqIDPayload, payloadTimeStamp,
  lat, lon, alt, HDOP, VDOP, PDOP, TDOP,
  hash, CRC
)
VALUES
  (
    10101010101010101010101010101010,
    10101010101010101010101010101010,
    2, 16962, '24/02/2020 10:00', 1, 680,
    -5, 10, 2, 263, 2531, 1, 10890, 63, 1,
    0, 0, 1, 0, 1, 16,-19, 12, 356, 34906,
    '23/02/2020 10:00', 55, 132, 187,
    58, 764,-715, 355, 1010101010101010101010101010101010101010101010101010101010101010,
    11995
  );
/* INSERT QUERY */
INSERT INTO DUMMYGPS(
  preamble, syncWord, packType, SCID,
  SCTime, timeSource, seqID, OBCTemp,
  battTemp, battVolt, battCurrent,
  chargeCurrent, antDep, dataPending,
  rebootCnt, rails1, rails2, rails3,
  rails4, rails5, rails6, RXTemp, TXTemp,
  PATemp, RXNoiseFloor, seqIDPayload, payloadTimeStamp,
  lat, lon, alt, HDOP, VDOP, PDOP, TDOP,
  hash, CRC
)
VALUES
  (
    10101010101010101010101010101010,
    10101010101010101010101010101010,
    2, 16962, '25/02/2020 10:00', 1, 11544,
    -7,-8, 2, 5290, 7617, 1, 6124, 111, 0,
    0, 0, 0, 1, 0,-21,-3,-7, 720, 16729,
    '24/02/2020 10:00', 29,-49, 171,
    -299, 272, 367, 642, 1010101010101010101010101010101010101010101010101010101010101010,
    50657
  );
/* INSERT QUERY */
INSERT INTO DUMMYGPS(
  preamble, syncWord, packType, SCID,
  SCTime, timeSource, seqID, OBCTemp,
  battTemp, battVolt, battCurrent,
  chargeCurrent, antDep, dataPending,
  rebootCnt, rails1, rails2, rails3,
  rails4, rails5, rails6, RXTemp, TXTemp,
  PATemp, RXNoiseFloor, seqIDPayload, payloadTimeStamp,
  lat, lon, alt, HDOP, VDOP, PDOP, TDOP,
  hash, CRC
)
VALUES
  (
    10101010101010101010101010101010,
    10101010101010101010101010101010,
    2, 16962, '26/02/2020 10:00', 1, 9687,
    6, 14, 2, 2561, 8536, 1, 5059, 248, 0,
    0, 0, 1, 0, 1,-11, 10, 22, 481, 15279,
    '25/02/2020 10:00', 72, 130, 197,
    -931, 137,-852, 196, 1010101010101010101010101010101010101010101010101010101010101010,
    57630
  );
/* INSERT QUERY */
INSERT INTO DUMMYGPS(
  preamble, syncWord, packType, SCID,
  SCTime, timeSource, seqID, OBCTemp,
  battTemp, battVolt, battCurrent,
  chargeCurrent, antDep, dataPending,
  rebootCnt, rails1, rails2, rails3,
  rails4, rails5, rails6, RXTemp, TXTemp,
  PATemp, RXNoiseFloor, seqIDPayload, payloadTimeStamp,
  lat, lon, alt, HDOP, VDOP, PDOP, TDOP,
  hash, CRC
)
VALUES
  (
    10101010101010101010101010101010,
    10101010101010101010101010101010,
    2, 16962, '27/02/2020 10:00', 1, 46949,
    -12,-13, 5, 337, 1908, 1, 8593, 203,
    0, 1, 0, 1, 0, 1, 1, 19, 25, 55, 600, '26/02/2020 10:00',
    -38,-18, 192,-479, 742, 191, 290, 1010101010101010101010101010101010101010101010101010101010101010,
    57394
  );
/* INSERT QUERY */
INSERT INTO DUMMYGPS(
  preamble, syncWord, packType, SCID,
  SCTime, timeSource, seqID, OBCTemp,
  battTemp, battVolt, battCurrent,
  chargeCurrent, antDep, dataPending,
  rebootCnt, rails1, rails2, rails3,
  rails4, rails5, rails6, RXTemp, TXTemp,
  PATemp, RXNoiseFloor, seqIDPayload, payloadTimeStamp,
  lat, lon, alt, HDOP, VDOP, PDOP, TDOP,
  hash, CRC
)
VALUES
  (
    10101010101010101010101010101010,
    10101010101010101010101010101010,
    2, 16962, '28/02/2020 10:00', 1, 29124,
    -22,-22, 5, 4935, 9835, 1, 7473, 144,
    0, 1, 1, 0, 0, 0,-22,-21, 22, 881, 21633,
    '27/02/2020 10:00', 64,-26, 214,
    -382,-283,-500, 492, 1010101010101010101010101010101010101010101010101010101010101010,
    1118
  );
/* INSERT QUERY */
INSERT INTO DUMMYGPS(
  preamble, syncWord, packType, SCID,
  SCTime, timeSource, seqID, OBCTemp,
  battTemp, battVolt, battCurrent,
  chargeCurrent, antDep, dataPending,
  rebootCnt, rails1, rails2, rails3,
  rails4, rails5, rails6, RXTemp, TXTemp,
  PATemp, RXNoiseFloor, seqIDPayload, payloadTimeStamp,
  lat, lon, alt, HDOP, VDOP, PDOP, TDOP,
  hash, CRC
)
VALUES
  (
    10101010101010101010101010101010,
    10101010101010101010101010101010,
    2, 16962, '29/02/2020 10:00', 1, 49565,
    19, 1, 2, 6555, 2091, 1, 2824, 170, 1,
    1, 1, 1, 1, 1, 20,-12, 9, 768, 35700, '28/02/2020 10:00',
    -47, 165, 100, 28, 910,-742,-741, 1010101010101010101010101010101010101010101010101010101010101010,
    45380
  );
/* INSERT QUERY */
INSERT INTO DUMMYGPS(
  preamble, syncWord, packType, SCID,
  SCTime, timeSource, seqID, OBCTemp,
  battTemp, battVolt, battCurrent,
  chargeCurrent, antDep, dataPending,
  rebootCnt, rails1, rails2, rails3,
  rails4, rails5, rails6, RXTemp, TXTemp,
  PATemp, RXNoiseFloor, seqIDPayload, payloadTimeStamp,
  lat, lon, alt, HDOP, VDOP, PDOP, TDOP,
  hash, CRC
)
VALUES
  (
    10101010101010101010101010101010,
    10101010101010101010101010101010,
    2, 16962, '01/03/2020 10:00', 1, 28421,
    -24,-8, 5, 8399, 765, 1, 2705, 250, 1,
    0, 0, 0, 0, 1, 19, 9,-4, 647, 22041, '29/02/2020 10:00',
    -18,-44, 228, 140, 552, 696, 736, 1010101010101010101010101010101010101010101010101010101010101010,
    49044
  );
/* INSERT QUERY */
INSERT INTO DUMMYGPS(
  preamble, syncWord, packType, SCID,
  SCTime, timeSource, seqID, OBCTemp,
  battTemp, battVolt, battCurrent,
  chargeCurrent, antDep, dataPending,
  rebootCnt, rails1, rails2, rails3,
  rails4, rails5, rails6, RXTemp, TXTemp,
  PATemp, RXNoiseFloor, seqIDPayload, payloadTimeStamp,
  lat, lon, alt, HDOP, VDOP, PDOP, TDOP,
  hash, CRC
)
VALUES
  (
    10101010101010101010101010101010,
    10101010101010101010101010101010,
    2, 16962, '02/03/2020 10:00', 1, 54637,
    17,-4, 3, 9539, 8826, 1, 18365, 109,
    1, 1, 1, 0, 0, 0, 16, 13, 21, 296, 2172,
    '01/03/2020 10:00', 13,-88, 118,
    778, 294,-387, 773, 1010101010101010101010101010101010101010101010101010101010101010,
    52128
  );
/* INSERT QUERY */
INSERT INTO DUMMYGPS(
  preamble, syncWord, packType, SCID,
  SCTime, timeSource, seqID, OBCTemp,
  battTemp, battVolt, battCurrent,
  chargeCurrent, antDep, dataPending,
  rebootCnt, rails1, rails2, rails3,
  rails4, rails5, rails6, RXTemp, TXTemp,
  PATemp, RXNoiseFloor, seqIDPayload, payloadTimeStamp,
  lat, lon, alt, HDOP, VDOP, PDOP, TDOP,
  hash, CRC
)
VALUES
  (
    10101010101010101010101010101010,
    10101010101010101010101010101010,
    2, 16962, '03/03/2020 10:00', 1, 11005,
    -24, 3, 5, 7883, 6834, 1, 15376, 133,
    1, 1, 1, 0, 0, 0, 20, 8,-15, 964, 45974,
    '02/03/2020 10:00',-1,-7, 194, 334,
    533,-469, 39, 1010101010101010101010101010101010101010101010101010101010101010,
    36449
  );
/* INSERT QUERY */
INSERT INTO DUMMYGPS(
  preamble, syncWord, packType, SCID,
  SCTime, timeSource, seqID, OBCTemp,
  battTemp, battVolt, battCurrent,
  chargeCurrent, antDep, dataPending,
  rebootCnt, rails1, rails2, rails3,
  rails4, rails5, rails6, RXTemp, TXTemp,
  PATemp, RXNoiseFloor, seqIDPayload, payloadTimeStamp,
  lat, lon, alt, HDOP, VDOP, PDOP, TDOP,
  hash, CRC
)
VALUES
  (
    10101010101010101010101010101010,
    10101010101010101010101010101010,
    2, 16962, '04/03/2020 10:00', 1, 43847,
    -21,-7, 2, 9969, 7385, 1, 3380, 45, 1,
    0, 0, 0, 1, 0, 2,-17, 9, 553, 45025, '03/03/2020 10:00',
    -28, 155, 105,-66,-618,-801,-329,
    1010101010101010101010101010101010101010101010101010101010101010,
    5596
  );
/* INSERT QUERY */
INSERT INTO DUMMYGPS(
  preamble, syncWord, packType, SCID,
  SCTime, timeSource, seqID, OBCTemp,
  battTemp, battVolt, battCurrent,
  chargeCurrent, antDep, dataPending,
  rebootCnt, rails1, rails2, rails3,
  rails4, rails5, rails6, RXTemp, TXTemp,
  PATemp, RXNoiseFloor, seqIDPayload, payloadTimeStamp,
  lat, lon, alt, HDOP, VDOP, PDOP, TDOP,
  hash, CRC
)
VALUES
  (
    10101010101010101010101010101010,
    10101010101010101010101010101010,
    2, 16962, '05/03/2020 10:00', 1, 53377,
    -7, 3, 5, 595, 3789, 1, 6302, 91, 1, 1,
    1, 0, 0, 1, 16, 10, 20, 198, 30763, '04/03/2020 10:00',
    -21, 122, 86,-956, 544,-202,-775,
    1010101010101010101010101010101010101010101010101010101010101010,
    57511
  );
/* INSERT QUERY */
INSERT INTO DUMMYGPS(
  preamble, syncWord, packType, SCID,
  SCTime, timeSource, seqID, OBCTemp,
  battTemp, battVolt, battCurrent,
  chargeCurrent, antDep, dataPending,
  rebootCnt, rails1, rails2, rails3,
  rails4, rails5, rails6, RXTemp, TXTemp,
  PATemp, RXNoiseFloor, seqIDPayload, payloadTimeStamp,
  lat, lon, alt, HDOP, VDOP, PDOP, TDOP,
  hash, CRC
)
VALUES
  (
    10101010101010101010101010101010,
    10101010101010101010101010101010,
    2, 16962, '06/03/2020 10:00', 1, 524,
    -19, 16, 1, 9313, 697, 1, 3992, 68, 1,
    0, 0, 1, 1, 0, 12, 17,-17, 390, 9581, '05/03/2020 10:00',
    -24,-75, 213, 725, 869, 797, 494, 1010101010101010101010101010101010101010101010101010101010101010,
    43279
  );
/* INSERT QUERY */
INSERT INTO DUMMYGPS(
  preamble, syncWord, packType, SCID,
  SCTime, timeSource, seqID, OBCTemp,
  battTemp, battVolt, battCurrent,
  chargeCurrent, antDep, dataPending,
  rebootCnt, rails1, rails2, rails3,
  rails4, rails5, rails6, RXTemp, TXTemp,
  PATemp, RXNoiseFloor, seqIDPayload, payloadTimeStamp,
  lat, lon, alt, HDOP, VDOP, PDOP, TDOP,
  hash, CRC
)
VALUES
  (
    10101010101010101010101010101010,
    10101010101010101010101010101010,
    2, 16962, '07/03/2020 10:00', 1, 16453,
    -11,-22, 4, 7393, 3774, 1, 30229, 37,
    1, 0, 1, 1, 0, 1,-25, 5, 24, 812, 7401,
    '06/03/2020 10:00', 80,-83, 165,
    658,-227, 0, 788, 1010101010101010101010101010101010101010101010101010101010101010,
    15885
  );
/* INSERT QUERY */
INSERT INTO DUMMYGPS(
  preamble, syncWord, packType, SCID,
  SCTime, timeSource, seqID, OBCTemp,
  battTemp, battVolt, battCurrent,
  chargeCurrent, antDep, dataPending,
  rebootCnt, rails1, rails2, rails3,
  rails4, rails5, rails6, RXTemp, TXTemp,
  PATemp, RXNoiseFloor, seqIDPayload, payloadTimeStamp,
  lat, lon, alt, HDOP, VDOP, PDOP, TDOP,
  hash, CRC
)
VALUES
  (
    10101010101010101010101010101010,
    10101010101010101010101010101010,
    2, 16962, '08/03/2020 10:00', 1, 53833,
    19,-15, 5, 6726, 2490, 1, 23080, 248,
    1, 0, 1, 1, 0, 0, 5,-22, 23, 313, 16368,
    '07/03/2020 10:00', 2,-32, 169, 524,
    196, 896,-11, 1010101010101010101010101010101010101010101010101010101010101010,
    44681
  );
/* INSERT QUERY */
INSERT INTO DUMMYGPS(
  preamble, syncWord, packType, SCID,
  SCTime, timeSource, seqID, OBCTemp,
  battTemp, battVolt, battCurrent,
  chargeCurrent, antDep, dataPending,
  rebootCnt, rails1, rails2, rails3,
  rails4, rails5, rails6, RXTemp, TXTemp,
  PATemp, RXNoiseFloor, seqIDPayload, payloadTimeStamp,
  lat, lon, alt, HDOP, VDOP, PDOP, TDOP,
  hash, CRC
)
VALUES
  (
    10101010101010101010101010101010,
    10101010101010101010101010101010,
    2, 16962, '09/03/2020 10:00', 1, 60689,
    -15,-8, 3, 4991, 725, 1, 1612, 253, 0,
    1, 1, 0, 0, 0,-7, 24, 10, 383, 55429, '08/03/2020 10:00',
    -40, 19, 159, 803, 470, 397,-692, 1010101010101010101010101010101010101010101010101010101010101010,
    25133
  );
/* INSERT QUERY */
INSERT INTO DUMMYGPS(
  preamble, syncWord, packType, SCID,
  SCTime, timeSource, seqID, OBCTemp,
  battTemp, battVolt, battCurrent,
  chargeCurrent, antDep, dataPending,
  rebootCnt, rails1, rails2, rails3,
  rails4, rails5, rails6, RXTemp, TXTemp,
  PATemp, RXNoiseFloor, seqIDPayload, payloadTimeStamp,
  lat, lon, alt, HDOP, VDOP, PDOP, TDOP,
  hash, CRC
)
VALUES
  (
    10101010101010101010101010101010,
    10101010101010101010101010101010,
    2, 16962, '10/03/2020 10:00', 1, 45134,
    18,-17, 5, 9064, 590, 1, 16643, 37, 0,
    0, 0, 0, 1, 0, 17, 15, 16, 674, 18086, '09/03/2020 10:00',
    86,-81, 146,-126,-954, 545,-859,
    1010101010101010101010101010101010101010101010101010101010101010,
    54609
  );
/* INSERT QUERY */
INSERT INTO DUMMYGPS(
  preamble, syncWord, packType, SCID,
  SCTime, timeSource, seqID, OBCTemp,
  battTemp, battVolt, battCurrent,
  chargeCurrent, antDep, dataPending,
  rebootCnt, rails1, rails2, rails3,
  rails4, rails5, rails6, RXTemp, TXTemp,
  PATemp, RXNoiseFloor, seqIDPayload, payloadTimeStamp,
  lat, lon, alt, HDOP, VDOP, PDOP, TDOP,
  hash, CRC
)
VALUES
  (
    10101010101010101010101010101010,
    10101010101010101010101010101010,
    2, 16962, '11/03/2020 10:00', 1, 14868,
    3, 21, 4, 8840, 3174, 1, 27016, 62, 1,
    1, 1, 1, 1, 0, 12,-1, 0, 950, 51748, '10/03/2020 10:00',
    -54,-91, 156,-885, 191,-278,-915,
    1010101010101010101010101010101010101010101010101010101010101010,
    49455
  );
/* INSERT QUERY */
INSERT INTO DUMMYGPS(
  preamble, syncWord, packType, SCID,
  SCTime, timeSource, seqID, OBCTemp,
  battTemp, battVolt, battCurrent,
  chargeCurrent, antDep, dataPending,
  rebootCnt, rails1, rails2, rails3,
  rails4, rails5, rails6, RXTemp, TXTemp,
  PATemp, RXNoiseFloor, seqIDPayload, payloadTimeStamp,
  lat, lon, alt, HDOP, VDOP, PDOP, TDOP,
  hash, CRC
)
VALUES
  (
    10101010101010101010101010101010,
    10101010101010101010101010101010,
    2, 16962, '12/03/2020 10:00', 1, 50548,
    -20, 16, 4, 4251, 1038, 1, 14164, 250,
    0, 1, 1, 0, 0, 1,-22,-11,-3, 253, 3637,
    '11/03/2020 10:00', 0,-89, 239, 940,
    -831,-26,-447, 1010101010101010101010101010101010101010101010101010101010101010,
    63756
  );
/* INSERT QUERY */
INSERT INTO DUMMYGPS(
  preamble, syncWord, packType, SCID,
  SCTime, timeSource, seqID, OBCTemp,
  battTemp, battVolt, battCurrent,
  chargeCurrent, antDep, dataPending,
  rebootCnt, rails1, rails2, rails3,
  rails4, rails5, rails6, RXTemp, TXTemp,
  PATemp, RXNoiseFloor, seqIDPayload, payloadTimeStamp,
  lat, lon, alt, HDOP, VDOP, PDOP, TDOP,
  hash, CRC
)
VALUES
  (
    10101010101010101010101010101010,
    10101010101010101010101010101010,
    2, 16962, '13/03/2020 10:00', 1, 5930,
    9, 12, 3, 4709, 5296, 1, 18191, 163, 0,
    1, 1, 1, 0, 0,-5, 7, 22, 222, 13151, '12/03/2020 10:00',
    -20,-150, 153, 988, 295, 379, 391, 1010101010101010101010101010101010101010101010101010101010101010,
    39115
  );
/* INSERT QUERY */
INSERT INTO DUMMYGPS(
  preamble, syncWord, packType, SCID,
  SCTime, timeSource, seqID, OBCTemp,
  battTemp, battVolt, battCurrent,
  chargeCurrent, antDep, dataPending,
  rebootCnt, rails1, rails2, rails3,
  rails4, rails5, rails6, RXTemp, TXTemp,
  PATemp, RXNoiseFloor, seqIDPayload, payloadTimeStamp,
  lat, lon, alt, HDOP, VDOP, PDOP, TDOP,
  hash, CRC
)
VALUES
  (
    10101010101010101010101010101010,
    10101010101010101010101010101010,
    2, 16962, '14/03/2020 10:00', 1, 19652,
    -21,-8, 4, 1284, 2782, 1, 17005, 145,
    0, 0, 0, 1, 1, 1,-11, 2,-7, 711, 25554,
    '13/03/2020 10:00',-29,-122, 131,
    -293, 92, 36,-860, 1010101010101010101010101010101010101010101010101010101010101010,
    44160
  );
/* INSERT QUERY */
INSERT INTO DUMMYGPS(
  preamble, syncWord, packType, SCID,
  SCTime, timeSource, seqID, OBCTemp,
  battTemp, battVolt, battCurrent,
  chargeCurrent, antDep, dataPending,
  rebootCnt, rails1, rails2, rails3,
  rails4, rails5, rails6, RXTemp, TXTemp,
  PATemp, RXNoiseFloor, seqIDPayload, payloadTimeStamp,
  lat, lon, alt, HDOP, VDOP, PDOP, TDOP,
  hash, CRC
)
VALUES
  (
    10101010101010101010101010101010,
    10101010101010101010101010101010,
    2, 16962, '15/03/2020 10:00', 1, 3770,
    -15, 23, 5, 389, 8735, 1, 24928, 172,
    0, 1, 0, 0, 1, 1, 5, 1,-3, 364, 29582, '14/03/2020 10:00',
    63, 5, 160, 15, 184, 386, 591, 1010101010101010101010101010101010101010101010101010101010101010,
    42928
  );
/* INSERT QUERY */
INSERT INTO DUMMYGPS(
  preamble, syncWord, packType, SCID,
  SCTime, timeSource, seqID, OBCTemp,
  battTemp, battVolt, battCurrent,
  chargeCurrent, antDep, dataPending,
  rebootCnt, rails1, rails2, rails3,
  rails4, rails5, rails6, RXTemp, TXTemp,
  PATemp, RXNoiseFloor, seqIDPayload, payloadTimeStamp,
  lat, lon, alt, HDOP, VDOP, PDOP, TDOP,
  hash, CRC
)
VALUES
  (
    10101010101010101010101010101010,
    10101010101010101010101010101010,
    2, 16962, '16/03/2020 10:00', 1, 52618,
    -21, 7, 5, 9799, 9681, 1, 22331, 43, 0,
    0, 0, 0, 0, 0, 25,-8,-18, 175, 58061,
    '15/03/2020 10:00',-7,-146, 231,
    40, 238, 714, 889, 1010101010101010101010101010101010101010101010101010101010101010,
    21927
  );
/* INSERT QUERY */
INSERT INTO DUMMYGPS(
  preamble, syncWord, packType, SCID,
  SCTime, timeSource, seqID, OBCTemp,
  battTemp, battVolt, battCurrent,
  chargeCurrent, antDep, dataPending,
  rebootCnt, rails1, rails2, rails3,
  rails4, rails5, rails6, RXTemp, TXTemp,
  PATemp, RXNoiseFloor, seqIDPayload, payloadTimeStamp,
  lat, lon, alt, HDOP, VDOP, PDOP, TDOP,
  hash, CRC
)
VALUES
  (
    10101010101010101010101010101010,
    10101010101010101010101010101010,
    2, 16962, '17/03/2020 10:00', 1, 1671,
    25,-10, 4, 7369, 5231, 1, 17854, 255,
    0, 0, 1, 1, 1, 1,-16, 19,-14, 484, 22493,
    '16/03/2020 10:00',-29, 77, 96,-626,
    -172,-770,-525, 1010101010101010101010101010101010101010101010101010101010101010,
    3194
  );
/* INSERT QUERY */
INSERT INTO DUMMYGPS(
  preamble, syncWord, packType, SCID,
  SCTime, timeSource, seqID, OBCTemp,
  battTemp, battVolt, battCurrent,
  chargeCurrent, antDep, dataPending,
  rebootCnt, rails1, rails2, rails3,
  rails4, rails5, rails6, RXTemp, TXTemp,
  PATemp, RXNoiseFloor, seqIDPayload, payloadTimeStamp,
  lat, lon, alt, HDOP, VDOP, PDOP, TDOP,
  hash, CRC
)
VALUES
  (
    10101010101010101010101010101010,
    10101010101010101010101010101010,
    2, 16962, '18/03/2020 10:00', 1, 33342,
    -1,-23, 5, 3095, 6498, 1, 13089, 220,
    1, 1, 1, 0, 0, 1,-11,-6, 21, 205, 30918,
    '17/03/2020 10:00',-3, 62, 121, 309,
    -836,-145,-323, 1010101010101010101010101010101010101010101010101010101010101010,
    57060
  );
/* INSERT QUERY */
INSERT INTO DUMMYGPS(
  preamble, syncWord, packType, SCID,
  SCTime, timeSource, seqID, OBCTemp,
  battTemp, battVolt, battCurrent,
  chargeCurrent, antDep, dataPending,
  rebootCnt, rails1, rails2, rails3,
  rails4, rails5, rails6, RXTemp, TXTemp,
  PATemp, RXNoiseFloor, seqIDPayload, payloadTimeStamp,
  lat, lon, alt, HDOP, VDOP, PDOP, TDOP,
  hash, CRC
)
VALUES
  (
    10101010101010101010101010101010,
    10101010101010101010101010101010,
    2, 16962, '19/03/2020 10:00', 1, 3359,
    12,-18, 3, 4336, 3942, 1, 18557, 166,
    0, 0, 0, 0, 0, 0, 24,-5,-11, 66, 23136,
    '18/03/2020 10:00', 51, 154, 159,
    683,-477, 349, 520, 1010101010101010101010101010101010101010101010101010101010101010,
    53436
  );
/* INSERT QUERY */
INSERT INTO DUMMYGPS(
  preamble, syncWord, packType, SCID,
  SCTime, timeSource, seqID, OBCTemp,
  battTemp, battVolt, battCurrent,
  chargeCurrent, antDep, dataPending,
  rebootCnt, rails1, rails2, rails3,
  rails4, rails5, rails6, RXTemp, TXTemp,
  PATemp, RXNoiseFloor, seqIDPayload, payloadTimeStamp,
  lat, lon, alt, HDOP, VDOP, PDOP, TDOP,
  hash, CRC
)
VALUES
  (
    10101010101010101010101010101010,
    10101010101010101010101010101010,
    2, 16962, '20/03/2020 10:00', 1, 15293,
    -19, 16, 4, 6897, 3943, 1, 28013, 8, 1,
    0, 1, 1, 1, 0, 21,-9,-12, 190, 43705,
    '19/03/2020 10:00',-14, 146, 124,
    -729, 842,-173,-551, 1010101010101010101010101010101010101010101010101010101010101010,
    2882
  );
/* INSERT QUERY */
INSERT INTO DUMMYGPS(
  preamble, syncWord, packType, SCID,
  SCTime, timeSource, seqID, OBCTemp,
  battTemp, battVolt, battCurrent,
  chargeCurrent, antDep, dataPending,
  rebootCnt, rails1, rails2, rails3,
  rails4, rails5, rails6, RXTemp, TXTemp,
  PATemp, RXNoiseFloor, seqIDPayload, payloadTimeStamp,
  lat, lon, alt, HDOP, VDOP, PDOP, TDOP,
  hash, CRC
)
VALUES
  (
    10101010101010101010101010101010,
    10101010101010101010101010101010,
    2, 16962, '21/03/2020 10:00', 1, 31817,
    11,-1, 2, 2908, 4667, 1, 11460, 123,
    0, 0, 0, 1, 1, 0, 24,-24,-11, 70, 9004,
    '20/03/2020 10:00', 19,-97, 82, 54,
    539,-334, 375, 1010101010101010101010101010101010101010101010101010101010101010,
    5277
  );
/* INSERT QUERY */
INSERT INTO DUMMYGPS(
  preamble, syncWord, packType, SCID,
  SCTime, timeSource, seqID, OBCTemp,
  battTemp, battVolt, battCurrent,
  chargeCurrent, antDep, dataPending,
  rebootCnt, rails1, rails2, rails3,
  rails4, rails5, rails6, RXTemp, TXTemp,
  PATemp, RXNoiseFloor, seqIDPayload, payloadTimeStamp,
  lat, lon, alt, HDOP, VDOP, PDOP, TDOP,
  hash, CRC
)
VALUES
  (
    10101010101010101010101010101010,
    10101010101010101010101010101010,
    2, 16962, '22/03/2020 10:00', 1, 28261,
    14,-3, 1, 5822, 1817, 1, 4184, 72, 0,
    1, 0, 0, 0, 1,-4, 8,-22, 743, 57691, '21/03/2020 10:00',
    68, 47, 244, 270, 59,-434, 318, 1010101010101010101010101010101010101010101010101010101010101010,
    29239
  );
/* INSERT QUERY */
INSERT INTO DUMMYGPS(
  preamble, syncWord, packType, SCID,
  SCTime, timeSource, seqID, OBCTemp,
  battTemp, battVolt, battCurrent,
  chargeCurrent, antDep, dataPending,
  rebootCnt, rails1, rails2, rails3,
  rails4, rails5, rails6, RXTemp, TXTemp,
  PATemp, RXNoiseFloor, seqIDPayload, payloadTimeStamp,
  lat, lon, alt, HDOP, VDOP, PDOP, TDOP,
  hash, CRC
)
VALUES
  (
    10101010101010101010101010101010,
    10101010101010101010101010101010,
    2, 16962, '23/03/2020 10:00', 1, 26025,
    -19, 7, 4, 5502, 8636, 1, 18587, 138,
    1, 0, 1, 1, 0, 1, 8, 14, 3, 35, 43306, '22/03/2020 10:00',
    -33,-37, 142,-73, 589, 825, 351, 1010101010101010101010101010101010101010101010101010101010101010,
    52740
  );
/* INSERT QUERY */
INSERT INTO DUMMYGPS(
  preamble, syncWord, packType, SCID,
  SCTime, timeSource, seqID, OBCTemp,
  battTemp, battVolt, battCurrent,
  chargeCurrent, antDep, dataPending,
  rebootCnt, rails1, rails2, rails3,
  rails4, rails5, rails6, RXTemp, TXTemp,
  PATemp, RXNoiseFloor, seqIDPayload, payloadTimeStamp,
  lat, lon, alt, HDOP, VDOP, PDOP, TDOP,
  hash, CRC
)
VALUES
  (
    10101010101010101010101010101010,
    10101010101010101010101010101010,
    2, 16962, '24/03/2020 10:00', 1, 34756,
    -22,-15, 3, 5721, 9827, 1, 29605, 253,
    1, 1, 1, 0, 0, 1, 0,-7,-12, 716, 25066,
    '23/03/2020 10:00', 71, 23, 149, 317,
    -156,-671,-450, 1010101010101010101010101010101010101010101010101010101010101010,
    55363
  );
/* INSERT QUERY */
INSERT INTO DUMMYGPS(
  preamble, syncWord, packType, SCID,
  SCTime, timeSource, seqID, OBCTemp,
  battTemp, battVolt, battCurrent,
  chargeCurrent, antDep, dataPending,
  rebootCnt, rails1, rails2, rails3,
  rails4, rails5, rails6, RXTemp, TXTemp,
  PATemp, RXNoiseFloor, seqIDPayload, payloadTimeStamp,
  lat, lon, alt, HDOP, VDOP, PDOP, TDOP,
  hash, CRC
)
VALUES
  (
    10101010101010101010101010101010,
    10101010101010101010101010101010,
    2, 16962, '25/03/2020 10:00', 1, 34102,
    10,-4, 4, 7963, 1593, 1, 28079, 222,
    0, 0, 0, 0, 0, 1, 24, 23, 10, 223, 32974,
    '24/03/2020 10:00', 36, 157, 186,
    391,-637, 95, 170, 1010101010101010101010101010101010101010101010101010101010101010,
    53771
  );
/* INSERT QUERY */
INSERT INTO DUMMYGPS(
  preamble, syncWord, packType, SCID,
  SCTime, timeSource, seqID, OBCTemp,
  battTemp, battVolt, battCurrent,
  chargeCurrent, antDep, dataPending,
  rebootCnt, rails1, rails2, rails3,
  rails4, rails5, rails6, RXTemp, TXTemp,
  PATemp, RXNoiseFloor, seqIDPayload, payloadTimeStamp,
  lat, lon, alt, HDOP, VDOP, PDOP, TDOP,
  hash, CRC
)
VALUES
  (
    10101010101010101010101010101010,
    10101010101010101010101010101010,
    2, 16962, '26/03/2020 10:00', 1, 52988,
    -13, 4, 2, 9363, 6374, 1, 5744, 204, 0,
    0, 1, 0, 0, 0,-3, 0, 0, 770, 40810, '25/03/2020 10:00',
    59,-2, 95,-915, 40,-676,-361, 1010101010101010101010101010101010101010101010101010101010101010,
    15371
  );
/* INSERT QUERY */
INSERT INTO DUMMYGPS(
  preamble, syncWord, packType, SCID,
  SCTime, timeSource, seqID, OBCTemp,
  battTemp, battVolt, battCurrent,
  chargeCurrent, antDep, dataPending,
  rebootCnt, rails1, rails2, rails3,
  rails4, rails5, rails6, RXTemp, TXTemp,
  PATemp, RXNoiseFloor, seqIDPayload, payloadTimeStamp,
  lat, lon, alt, HDOP, VDOP, PDOP, TDOP,
  hash, CRC
)
VALUES
  (
    10101010101010101010101010101010,
    10101010101010101010101010101010,
    2, 16962, '27/03/2020 10:00', 1, 12717,
    25, 11, 1, 4210, 7947, 1, 17967, 167,
    0, 1, 0, 1, 1, 1,-20,-25, 19, 124, 8362,
    '26/03/2020 10:00',-76,-105, 148,
    293, 143,-62,-267, 1010101010101010101010101010101010101010101010101010101010101010,
    20647
  );
/* INSERT QUERY */
INSERT INTO DUMMYGPS(
  preamble, syncWord, packType, SCID,
  SCTime, timeSource, seqID, OBCTemp,
  battTemp, battVolt, battCurrent,
  chargeCurrent, antDep, dataPending,
  rebootCnt, rails1, rails2, rails3,
  rails4, rails5, rails6, RXTemp, TXTemp,
  PATemp, RXNoiseFloor, seqIDPayload, payloadTimeStamp,
  lat, lon, alt, HDOP, VDOP, PDOP, TDOP,
  hash, CRC
)
VALUES
  (
    10101010101010101010101010101010,
    10101010101010101010101010101010,
    2, 16962, '28/03/2020 10:00', 1, 14054,
    4, 24, 5, 2494, 643, 1, 13964, 117, 1,
    0, 0, 1, 0, 1,-6, 24, 15, 943, 9327, '27/03/2020 10:00',
    -88, 121, 130, 671, 723,-606, 530, 1010101010101010101010101010101010101010101010101010101010101010,
    35198
  );
/* INSERT QUERY */
INSERT INTO DUMMYGPS(
  preamble, syncWord, packType, SCID,
  SCTime, timeSource, seqID, OBCTemp,
  battTemp, battVolt, battCurrent,
  chargeCurrent, antDep, dataPending,
  rebootCnt, rails1, rails2, rails3,
  rails4, rails5, rails6, RXTemp, TXTemp,
  PATemp, RXNoiseFloor, seqIDPayload, payloadTimeStamp,
  lat, lon, alt, HDOP, VDOP, PDOP, TDOP,
  hash, CRC
)
VALUES
  (
    10101010101010101010101010101010,
    10101010101010101010101010101010,
    2, 16962, '29/03/2020 10:00', 1, 21443,
    -16, 18, 4, 8846, 4042, 1, 22607, 10,
    0, 1, 1, 0, 0, 1,-23,-5, 4, 623, 15211,
    '28/03/2020 10:00',-62,-130, 118,
    523, 917,-672,-807, 1010101010101010101010101010101010101010101010101010101010101010,
    64715
  );
/* INSERT QUERY */
INSERT INTO DUMMYGPS(
  preamble, syncWord, packType, SCID,
  SCTime, timeSource, seqID, OBCTemp,
  battTemp, battVolt, battCurrent,
  chargeCurrent, antDep, dataPending,
  rebootCnt, rails1, rails2, rails3,
  rails4, rails5, rails6, RXTemp, TXTemp,
  PATemp, RXNoiseFloor, seqIDPayload, payloadTimeStamp,
  lat, lon, alt, HDOP, VDOP, PDOP, TDOP,
  hash, CRC
)
VALUES
  (
    10101010101010101010101010101010,
    10101010101010101010101010101010,
    2, 16962, '30/03/2020 10:00', 1, 42521,
    -3, 15, 1, 5458, 772, 1, 24105, 104, 0,
    0, 1, 1, 0, 0, 11,-13,-2, 69, 53811, '29/03/2020 10:00',
    -22,-137, 90, 425,-860, 606,-377,
    1010101010101010101010101010101010101010101010101010101010101010,
    2734
  );
/* INSERT QUERY */
INSERT INTO DUMMYGPS(
  preamble, syncWord, packType, SCID,
  SCTime, timeSource, seqID, OBCTemp,
  battTemp, battVolt, battCurrent,
  chargeCurrent, antDep, dataPending,
  rebootCnt, rails1, rails2, rails3,
  rails4, rails5, rails6, RXTemp, TXTemp,
  PATemp, RXNoiseFloor, seqIDPayload, payloadTimeStamp,
  lat, lon, alt, HDOP, VDOP, PDOP, TDOP,
  hash, CRC
)
VALUES
  (
    10101010101010101010101010101010,
    10101010101010101010101010101010,
    2, 16962, '31/03/2020 10:00', 1, 22856,
    -3,-21, 0, 5079, 941, 1, 19356, 218,
    0, 1, 1, 1, 0, 1, 23,-17,-5, 874, 28166,
    '30/03/2020 10:00', 68, 141, 242,
    356, 208, 426, 636, 1010101010101010101010101010101010101010101010101010101010101010,
    5942
  );
/* INSERT QUERY */
INSERT INTO DUMMYGPS(
  preamble, syncWord, packType, SCID,
  SCTime, timeSource, seqID, OBCTemp,
  battTemp, battVolt, battCurrent,
  chargeCurrent, antDep, dataPending,
  rebootCnt, rails1, rails2, rails3,
  rails4, rails5, rails6, RXTemp, TXTemp,
  PATemp, RXNoiseFloor, seqIDPayload, payloadTimeStamp,
  lat, lon, alt, HDOP, VDOP, PDOP, TDOP,
  hash, CRC
)
VALUES
  (
    10101010101010101010101010101010,
    10101010101010101010101010101010,
    2, 16962, '01/04/2020 10:00', 1, 33458,
    13, 25, 2, 9892, 5845, 1, 3997, 34, 1,
    0, 1, 0, 0, 0,-12, 2,-17, 697, 55326,
    '31/03/2020 10:00',-80,-69, 180,
    -592, 283, 353, 799, 1010101010101010101010101010101010101010101010101010101010101010,
    65407
  );
/* INSERT QUERY */
INSERT INTO DUMMYGPS(
  preamble, syncWord, packType, SCID,
  SCTime, timeSource, seqID, OBCTemp,
  battTemp, battVolt, battCurrent,
  chargeCurrent, antDep, dataPending,
  rebootCnt, rails1, rails2, rails3,
  rails4, rails5, rails6, RXTemp, TXTemp,
  PATemp, RXNoiseFloor, seqIDPayload, payloadTimeStamp,
  lat, lon, alt, HDOP, VDOP, PDOP, TDOP,
  hash, CRC
)
VALUES
  (
    10101010101010101010101010101010,
    10101010101010101010101010101010,
    2, 16962, '02/04/2020 10:00', 1, 34170,
    -17,-10, 2, 5150, 2144, 1, 1948, 138,
    1, 1, 1, 0, 0, 1,-9, 24, 0, 600, 64307,
    '01/04/2020 10:00', 44, 98, 145, 974,
    -432, 301,-829, 1010101010101010101010101010101010101010101010101010101010101010,
    50673
  );
/* INSERT QUERY */
INSERT INTO DUMMYGPS(
  preamble, syncWord, packType, SCID,
  SCTime, timeSource, seqID, OBCTemp,
  battTemp, battVolt, battCurrent,
  chargeCurrent, antDep, dataPending,
  rebootCnt, rails1, rails2, rails3,
  rails4, rails5, rails6, RXTemp, TXTemp,
  PATemp, RXNoiseFloor, seqIDPayload, payloadTimeStamp,
  lat, lon, alt, HDOP, VDOP, PDOP, TDOP,
  hash, CRC
)
VALUES
  (
    10101010101010101010101010101010,
    10101010101010101010101010101010,
    2, 16962, '03/04/2020 10:00', 1, 1571,
    -9, 22, 4, 9340, 2392, 1, 20133, 197,
    1, 0, 1, 0, 1, 1, 1,-14, 14, 643, 2369,
    '02/04/2020 10:00',-84, 140, 144,
    -149,-751,-436,-973, 1010101010101010101010101010101010101010101010101010101010101010,
    25458
  );
/* INSERT QUERY */
INSERT INTO DUMMYGPS(
  preamble, syncWord, packType, SCID,
  SCTime, timeSource, seqID, OBCTemp,
  battTemp, battVolt, battCurrent,
  chargeCurrent, antDep, dataPending,
  rebootCnt, rails1, rails2, rails3,
  rails4, rails5, rails6, RXTemp, TXTemp,
  PATemp, RXNoiseFloor, seqIDPayload, payloadTimeStamp,
  lat, lon, alt, HDOP, VDOP, PDOP, TDOP,
  hash, CRC
)
VALUES
  (
    10101010101010101010101010101010,
    10101010101010101010101010101010,
    2, 16962, '04/04/2020 10:00', 1, 61292,
    9,-7, 1, 7260, 1219, 1, 4939, 223, 1,
    1, 1, 1, 1, 1,-10, 12,-16, 695, 9766,
    '03/04/2020 10:00',-46,-55, 197,
    -157,-81, 697,-200, 1010101010101010101010101010101010101010101010101010101010101010,
    14404
  );
/* INSERT QUERY */
INSERT INTO DUMMYGPS(
  preamble, syncWord, packType, SCID,
  SCTime, timeSource, seqID, OBCTemp,
  battTemp, battVolt, battCurrent,
  chargeCurrent, antDep, dataPending,
  rebootCnt, rails1, rails2, rails3,
  rails4, rails5, rails6, RXTemp, TXTemp,
  PATemp, RXNoiseFloor, seqIDPayload, payloadTimeStamp,
  lat, lon, alt, HDOP, VDOP, PDOP, TDOP,
  hash, CRC
)
VALUES
  (
    10101010101010101010101010101010,
    10101010101010101010101010101010,
    2, 16962, '05/04/2020 10:00', 0, 10786,
    -22,-14, 1, 3586, 9250, 1, 31436, 30,
    1, 1, 1, 0, 0, 1, 25,-15,-16, 784, 46735,
    '04/04/2020 10:00', 82, 114, 156,
    791,-191,-289, 1, 1010101010101010101010101010101010101010101010101010101010101010,
    22782
  );
/* INSERT QUERY */
INSERT INTO DUMMYGPS(
  preamble, syncWord, packType, SCID,
  SCTime, timeSource, seqID, OBCTemp,
  battTemp, battVolt, battCurrent,
  chargeCurrent, antDep, dataPending,
  rebootCnt, rails1, rails2, rails3,
  rails4, rails5, rails6, RXTemp, TXTemp,
  PATemp, RXNoiseFloor, seqIDPayload, payloadTimeStamp,
  lat, lon, alt, HDOP, VDOP, PDOP, TDOP,
  hash, CRC
)
VALUES
  (
    10101010101010101010101010101010,
    10101010101010101010101010101010,
    2, 16962, '06/04/2020 10:00', 0, 47538,
    -20, 5, 0, 6191, 5916, 1, 28860, 211,
    0, 1, 0, 0, 0, 1, 0, 3, 22, 289, 64527, '05/04/2020 10:00',
    -10, 9, 146, 36, 864,-65, 607, 1010101010101010101010101010101010101010101010101010101010101010,
    50989
  );
/* INSERT QUERY */
INSERT INTO DUMMYGPS(
  preamble, syncWord, packType, SCID,
  SCTime, timeSource, seqID, OBCTemp,
  battTemp, battVolt, battCurrent,
  chargeCurrent, antDep, dataPending,
  rebootCnt, rails1, rails2, rails3,
  rails4, rails5, rails6, RXTemp, TXTemp,
  PATemp, RXNoiseFloor, seqIDPayload, payloadTimeStamp,
  lat, lon, alt, HDOP, VDOP, PDOP, TDOP,
  hash, CRC
)
VALUES
  (
    10101010101010101010101010101010,
    10101010101010101010101010101010,
    2, 16962, '07/04/2020 10:00', 0, 39620,
    -9,-11, 1, 4147, 6751, 1, 30629, 42,
    0, 0, 0, 0, 0, 1, 11,-14, 13, 30, 20220,
    '06/04/2020 10:00', 62, 26, 180, 321,
    971, 683, 595, 1010101010101010101010101010101010101010101010101010101010101010,
    33241
  );
/* INSERT QUERY */
INSERT INTO DUMMYGPS(
  preamble, syncWord, packType, SCID,
  SCTime, timeSource, seqID, OBCTemp,
  battTemp, battVolt, battCurrent,
  chargeCurrent, antDep, dataPending,
  rebootCnt, rails1, rails2, rails3,
  rails4, rails5, rails6, RXTemp, TXTemp,
  PATemp, RXNoiseFloor, seqIDPayload, payloadTimeStamp,
  lat, lon, alt, HDOP, VDOP, PDOP, TDOP,
  hash, CRC
)
VALUES
  (
    10101010101010101010101010101010,
    10101010101010101010101010101010,
    2, 16962, '08/04/2020 10:00', 0, 49825,
    -14, 13, 0, 6910, 8660, 1, 28988, 212,
    1, 0, 1, 0, 0, 1,-2, 3,-3, 579, 7148, '07/04/2020 10:00',
    23,-64, 166,-359,-906,-849, 112,
    1010101010101010101010101010101010101010101010101010101010101010,
    10966
  );
/* INSERT QUERY */
INSERT INTO DUMMYGPS(
  preamble, syncWord, packType, SCID,
  SCTime, timeSource, seqID, OBCTemp,
  battTemp, battVolt, battCurrent,
  chargeCurrent, antDep, dataPending,
  rebootCnt, rails1, rails2, rails3,
  rails4, rails5, rails6, RXTemp, TXTemp,
  PATemp, RXNoiseFloor, seqIDPayload, payloadTimeStamp,
  lat, lon, alt, HDOP, VDOP, PDOP, TDOP,
  hash, CRC
)
VALUES
  (
    10101010101010101010101010101010,
    10101010101010101010101010101010,
    2, 16962, '09/04/2020 10:00', 0, 58340,
    18, 0, 3, 6202, 4229, 1, 12231, 215, 1,
    1, 1, 1, 0, 1, 18, 14, 13, 312, 51197, '08/04/2020 10:00',
    -71,-136, 149,-2,-793,-381, 950,
    1010101010101010101010101010101010101010101010101010101010101010,
    47851
  );
