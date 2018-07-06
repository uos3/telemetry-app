/* CREATE TABLE */
CREATE TABLE IF NOT EXISTS STATUS(
  packID INT(11),
  seqStat DECIMAL(10, 2),
  SCID DECIMAL(10, 2),
  SCTime VARCHAR(100),
  timeSource DECIMAL(10, 2),
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
  RXNoiseFloor DECIMAL(10, 2)
);

  /* CREATE TABLE */
  CREATE TABLE IF NOT EXISTS GPS(
    packID INT(11),
    seqPayload DECIMAL(10, 2),
    payloadTimeStamp VARCHAR(100),
    lat DECIMAL(10, 2),
    lon DECIMAL(10, 2),
    alt DECIMAL(10, 2),
    HDOP DECIMAL(10, 2),
    VDOP DECIMAL(10, 2),
    PDOP DECIMAL(10, 2),
    TDOP DECIMAL(10, 2)
  );

/* INSERT QUERY */
INSERT INTO STATUS(
  packID, seqStat, SCID, SCTime, timeSource,
  OBCTemp, battTemp, battVolt, battCurrent,
  chargeCurrent, antDep, dataPending,
  rebootCnt, rails1, rails2, rails3,
  rails4, rails5, rails6, RXTemp, TXTemp,
  PATemp, RXNoiseFloor
)
VALUES
  (
    1, 10317, 16962, '01/01/2020 10:00',
    0, 9,-19, 3, 6623, 2682, 0, 48255, 208,
    1, 1, 0, 0, 1, 1, 11, 22, 11, 221
  );
/* INSERT QUERY */
INSERT INTO STATUS(
  packID, seqStat, SCID, SCTime, timeSource,
  OBCTemp, battTemp, battVolt, battCurrent,
  chargeCurrent, antDep, dataPending,
  rebootCnt, rails1, rails2, rails3,
  rails4, rails5, rails6, RXTemp, TXTemp,
  PATemp, RXNoiseFloor
)
VALUES
  (
    2, 2900, 16962, '02/01/2020 10:00',
    0,-24,-11, 3, 5588, 5863, 0, 39000,
    131, 1, 1, 0, 0, 0, 0,-17, 7, 16, 290
  );
/* INSERT QUERY */
INSERT INTO STATUS(
  packID, seqStat, SCID, SCTime, timeSource,
  OBCTemp, battTemp, battVolt, battCurrent,
  chargeCurrent, antDep, dataPending,
  rebootCnt, rails1, rails2, rails3,
  rails4, rails5, rails6, RXTemp, TXTemp,
  PATemp, RXNoiseFloor
)
VALUES
  (
    3, 29220, 16962, '03/01/2020 10:00',
    0, 16,-1, 1, 3056, 9482, 0, 6132, 23,
    1, 1, 1, 1, 0, 0,-10, 25, 1, 261
  );
/* INSERT QUERY */
INSERT INTO STATUS(
  packID, seqStat, SCID, SCTime, timeSource,
  OBCTemp, battTemp, battVolt, battCurrent,
  chargeCurrent, antDep, dataPending,
  rebootCnt, rails1, rails2, rails3,
  rails4, rails5, rails6, RXTemp, TXTemp,
  PATemp, RXNoiseFloor
)
VALUES
  (
    4, 33774, 16962, '04/01/2020 10:00',
    0, 14, 8, 3, 8000, 1161, 0, 20288, 48,
    0, 1, 0, 1, 1, 0, 2, 19, 13, 942
  );
/* INSERT QUERY */
INSERT INTO STATUS(
  packID, seqStat, SCID, SCTime, timeSource,
  OBCTemp, battTemp, battVolt, battCurrent,
  chargeCurrent, antDep, dataPending,
  rebootCnt, rails1, rails2, rails3,
  rails4, rails5, rails6, RXTemp, TXTemp,
  PATemp, RXNoiseFloor
)
VALUES
  (
    5, 34564, 16962, '05/01/2020 10:00',
    0,-6,-15, 3, 2410, 3252, 0, 1657, 53,
    1, 1, 0, 1, 0, 1,-9,-17,-20, 712
  );
/* INSERT QUERY */
INSERT INTO STATUS(
  packID, seqStat, SCID, SCTime, timeSource,
  OBCTemp, battTemp, battVolt, battCurrent,
  chargeCurrent, antDep, dataPending,
  rebootCnt, rails1, rails2, rails3,
  rails4, rails5, rails6, RXTemp, TXTemp,
  PATemp, RXNoiseFloor
)
VALUES
  (
    6, 24048, 16962, '06/01/2020 10:00',
    0, 0, 14, 1, 7165, 9714, 0, 44843, 125,
    1, 1, 1, 0, 1, 0, 23, 16,-5, 48
  );
/* INSERT QUERY */
INSERT INTO STATUS(
  packID, seqStat, SCID, SCTime, timeSource,
  OBCTemp, battTemp, battVolt, battCurrent,
  chargeCurrent, antDep, dataPending,
  rebootCnt, rails1, rails2, rails3,
  rails4, rails5, rails6, RXTemp, TXTemp,
  PATemp, RXNoiseFloor
)
VALUES
  (
    7, 43447, 16962, '07/01/2020 10:00',
    0,-10,-10, 0, 2309, 6815, 0, 15519,
    175, 1, 0, 1, 1, 0, 0,-25,-16,-9, 6
  );
/* INSERT QUERY */
INSERT INTO STATUS(
  packID, seqStat, SCID, SCTime, timeSource,
  OBCTemp, battTemp, battVolt, battCurrent,
  chargeCurrent, antDep, dataPending,
  rebootCnt, rails1, rails2, rails3,
  rails4, rails5, rails6, RXTemp, TXTemp,
  PATemp, RXNoiseFloor
)
VALUES
  (
    8, 20368, 16962, '08/01/2020 10:00',
    0, 15,-14, 5, 7444, 1189, 0, 323, 117,
    1, 1, 1, 0, 1, 0, 25, 23,-19, 778
  );
/* INSERT QUERY */
INSERT INTO STATUS(
  packID, seqStat, SCID, SCTime, timeSource,
  OBCTemp, battTemp, battVolt, battCurrent,
  chargeCurrent, antDep, dataPending,
  rebootCnt, rails1, rails2, rails3,
  rails4, rails5, rails6, RXTemp, TXTemp,
  PATemp, RXNoiseFloor
)
VALUES
  (
    9, 44235, 16962, '09/01/2020 10:00',
    0,-9, 16, 0, 5596, 9975, 0, 26429, 81,
    0, 1, 0, 1, 0, 0, 21,-21,-10, 381
  );
/* INSERT QUERY */
INSERT INTO STATUS(
  packID, seqStat, SCID, SCTime, timeSource,
  OBCTemp, battTemp, battVolt, battCurrent,
  chargeCurrent, antDep, dataPending,
  rebootCnt, rails1, rails2, rails3,
  rails4, rails5, rails6, RXTemp, TXTemp,
  PATemp, RXNoiseFloor
)
VALUES
  (
    10, 49683, 16962, '10/01/2020 10:00',
    0, 6, 4, 1, 6280, 9947, 0, 36082, 164,
    0, 1, 0, 0, 0, 0,-18,-23,-24, 860
  );
/* INSERT QUERY */
INSERT INTO STATUS(
  packID, seqStat, SCID, SCTime, timeSource,
  OBCTemp, battTemp, battVolt, battCurrent,
  chargeCurrent, antDep, dataPending,
  rebootCnt, rails1, rails2, rails3,
  rails4, rails5, rails6, RXTemp, TXTemp,
  PATemp, RXNoiseFloor
)
VALUES
  (
    11, 44131, 16962, '11/01/2020 10:00',
    0, 16, 15, 4, 1317, 9382, 1, 62987, 32,
    1, 1, 0, 0, 0, 0,-20,-18,-23, 807
  );
/* INSERT QUERY */
INSERT INTO STATUS(
  packID, seqStat, SCID, SCTime, timeSource,
  OBCTemp, battTemp, battVolt, battCurrent,
  chargeCurrent, antDep, dataPending,
  rebootCnt, rails1, rails2, rails3,
  rails4, rails5, rails6, RXTemp, TXTemp,
  PATemp, RXNoiseFloor
)
VALUES
  (
    12, 27387, 16962, '12/01/2020 10:00',
    0, 6,-12, 3, 4309, 3194, 1, 47226, 248,
    1, 1, 1, 1, 1, 1, 4,-11, 10, 296
  );
/* INSERT QUERY */
INSERT INTO STATUS(
  packID, seqStat, SCID, SCTime, timeSource,
  OBCTemp, battTemp, battVolt, battCurrent,
  chargeCurrent, antDep, dataPending,
  rebootCnt, rails1, rails2, rails3,
  rails4, rails5, rails6, RXTemp, TXTemp,
  PATemp, RXNoiseFloor
)
VALUES
  (
    13, 30145, 16962, '13/01/2020 10:00',
    0,-7,-19, 5, 5835, 8312, 1, 46866, 118,
    0, 1, 0, 1, 1, 0, 8,-23, 8, 647
  );
/* INSERT QUERY */
INSERT INTO STATUS(
  packID, seqStat, SCID, SCTime, timeSource,
  OBCTemp, battTemp, battVolt, battCurrent,
  chargeCurrent, antDep, dataPending,
  rebootCnt, rails1, rails2, rails3,
  rails4, rails5, rails6, RXTemp, TXTemp,
  PATemp, RXNoiseFloor
)
VALUES
  (
    14, 2998, 16962, '14/01/2020 10:00',
    0, 5, 18, 5, 6995, 8855, 1, 64968, 69,
    1, 1, 1, 0, 1, 1, 1, 9,-6, 135
  );
/* INSERT QUERY */
INSERT INTO STATUS(
  packID, seqStat, SCID, SCTime, timeSource,
  OBCTemp, battTemp, battVolt, battCurrent,
  chargeCurrent, antDep, dataPending,
  rebootCnt, rails1, rails2, rails3,
  rails4, rails5, rails6, RXTemp, TXTemp,
  PATemp, RXNoiseFloor
)
VALUES
  (
    15, 47482, 16962, '15/01/2020 10:00',
    0, 3, 11, 2, 3155, 7033, 1, 20992, 90,
    0, 1, 1, 1, 1, 0,-24,-23, 4, 387
  );
/* INSERT QUERY */
INSERT INTO STATUS(
  packID, seqStat, SCID, SCTime, timeSource,
  OBCTemp, battTemp, battVolt, battCurrent,
  chargeCurrent, antDep, dataPending,
  rebootCnt, rails1, rails2, rails3,
  rails4, rails5, rails6, RXTemp, TXTemp,
  PATemp, RXNoiseFloor
)
VALUES
  (
    16, 40527, 16962, '16/01/2020 10:00',
    0, 8, 11, 0, 4508, 6085, 1, 10654, 83,
    1, 1, 0, 1, 1, 1,-8,-24,-19, 675
  );
/* INSERT QUERY */
INSERT INTO STATUS(
  packID, seqStat, SCID, SCTime, timeSource,
  OBCTemp, battTemp, battVolt, battCurrent,
  chargeCurrent, antDep, dataPending,
  rebootCnt, rails1, rails2, rails3,
  rails4, rails5, rails6, RXTemp, TXTemp,
  PATemp, RXNoiseFloor
)
VALUES
  (
    17, 15623, 16962, '17/01/2020 10:00',
    0,-20, 15, 0, 3399, 6572, 1, 30624, 153,
    1, 0, 0, 0, 0, 0,-24,-16, 18, 333
  );
/* INSERT QUERY */
INSERT INTO STATUS(
  packID, seqStat, SCID, SCTime, timeSource,
  OBCTemp, battTemp, battVolt, battCurrent,
  chargeCurrent, antDep, dataPending,
  rebootCnt, rails1, rails2, rails3,
  rails4, rails5, rails6, RXTemp, TXTemp,
  PATemp, RXNoiseFloor
)
VALUES
  (
    18, 27462, 16962, '18/01/2020 10:00',
    0, 21, 8, 0, 3688, 8767, 1, 22005, 39,
    1, 1, 0, 1, 0, 1, 4,-11,-23, 119
  );
/* INSERT QUERY */
INSERT INTO STATUS(
  packID, seqStat, SCID, SCTime, timeSource,
  OBCTemp, battTemp, battVolt, battCurrent,
  chargeCurrent, antDep, dataPending,
  rebootCnt, rails1, rails2, rails3,
  rails4, rails5, rails6, RXTemp, TXTemp,
  PATemp, RXNoiseFloor
)
VALUES
  (
    19, 50200, 16962, '19/01/2020 10:00',
    0, 7,-12, 0, 3438, 199, 1, 61428, 233,
    1, 1, 0, 1, 0, 1,-14,-19, 8, 4
  );
/* INSERT QUERY */
INSERT INTO STATUS(
  packID, seqStat, SCID, SCTime, timeSource,
  OBCTemp, battTemp, battVolt, battCurrent,
  chargeCurrent, antDep, dataPending,
  rebootCnt, rails1, rails2, rails3,
  rails4, rails5, rails6, RXTemp, TXTemp,
  PATemp, RXNoiseFloor
)
VALUES
  (
    20, 37682, 16962, '20/01/2020 10:00',
    0, 15,-10, 3, 8248, 6562, 1, 27735, 70,
    1, 1, 1, 1, 0, 0,-4,-20,-16, 315
  );
/* INSERT QUERY */
INSERT INTO STATUS(
  packID, seqStat, SCID, SCTime, timeSource,
  OBCTemp, battTemp, battVolt, battCurrent,
  chargeCurrent, antDep, dataPending,
  rebootCnt, rails1, rails2, rails3,
  rails4, rails5, rails6, RXTemp, TXTemp,
  PATemp, RXNoiseFloor
)
VALUES
  (
    21, 53740, 16962, '21/01/2020 10:00',
    0, 5,-6, 3, 2734, 9847, 1, 39411, 171,
    0, 0, 1, 0, 1, 0, 23,-3,-17, 109
  );
/* INSERT QUERY */
INSERT INTO STATUS(
  packID, seqStat, SCID, SCTime, timeSource,
  OBCTemp, battTemp, battVolt, battCurrent,
  chargeCurrent, antDep, dataPending,
  rebootCnt, rails1, rails2, rails3,
  rails4, rails5, rails6, RXTemp, TXTemp,
  PATemp, RXNoiseFloor
)
VALUES
  (
    22, 45688, 16962, '22/01/2020 10:00',
    0,-18,-22, 4, 3654, 1396, 1, 13538,
    160, 0, 0, 0, 0, 0, 0,-3, 8,-21, 579
  );
/* INSERT QUERY */
INSERT INTO STATUS(
  packID, seqStat, SCID, SCTime, timeSource,
  OBCTemp, battTemp, battVolt, battCurrent,
  chargeCurrent, antDep, dataPending,
  rebootCnt, rails1, rails2, rails3,
  rails4, rails5, rails6, RXTemp, TXTemp,
  PATemp, RXNoiseFloor
)
VALUES
  (
    23, 19056, 16962, '23/01/2020 10:00',
    0, 7, 17, 2, 9928, 2512, 1, 19326, 233,
    1, 1, 0, 1, 0, 0,-16, 12, 7, 151
  );
/* INSERT QUERY */
INSERT INTO STATUS(
  packID, seqStat, SCID, SCTime, timeSource,
  OBCTemp, battTemp, battVolt, battCurrent,
  chargeCurrent, antDep, dataPending,
  rebootCnt, rails1, rails2, rails3,
  rails4, rails5, rails6, RXTemp, TXTemp,
  PATemp, RXNoiseFloor
)
VALUES
  (
    24, 42484, 16962, '24/01/2020 10:00',
    0, 4,-9, 2, 4202, 8719, 1, 57435, 178,
    0, 0, 0, 0, 1, 0,-24, 18, 18, 913
  );
/* INSERT QUERY */
INSERT INTO STATUS(
  packID, seqStat, SCID, SCTime, timeSource,
  OBCTemp, battTemp, battVolt, battCurrent,
  chargeCurrent, antDep, dataPending,
  rebootCnt, rails1, rails2, rails3,
  rails4, rails5, rails6, RXTemp, TXTemp,
  PATemp, RXNoiseFloor
)
VALUES
  (
    25, 60226, 16962, '25/01/2020 10:00',
    0,-12,-16, 0, 2114, 4401, 1, 30277,
    161, 0, 0, 0, 1, 0, 1,-23,-9, 12, 664
  );
/* INSERT QUERY */
INSERT INTO STATUS(
  packID, seqStat, SCID, SCTime, timeSource,
  OBCTemp, battTemp, battVolt, battCurrent,
  chargeCurrent, antDep, dataPending,
  rebootCnt, rails1, rails2, rails3,
  rails4, rails5, rails6, RXTemp, TXTemp,
  PATemp, RXNoiseFloor
)
VALUES
  (
    26, 43459, 16962, '26/01/2020 10:00',
    0,-9, 17, 0, 4410, 1452, 1, 12782, 144,
    1, 0, 1, 0, 1, 0, 9, 17,-20, 393
  );
/* INSERT QUERY */
INSERT INTO STATUS(
  packID, seqStat, SCID, SCTime, timeSource,
  OBCTemp, battTemp, battVolt, battCurrent,
  chargeCurrent, antDep, dataPending,
  rebootCnt, rails1, rails2, rails3,
  rails4, rails5, rails6, RXTemp, TXTemp,
  PATemp, RXNoiseFloor
)
VALUES
  (
    27, 10320, 16962, '27/01/2020 10:00',
    0,-21,-13, 1, 2126, 5053, 1, 23497,
    174, 0, 1, 1, 0, 1, 0,-2,-7, 4, 951
  );
/* INSERT QUERY */
INSERT INTO STATUS(
  packID, seqStat, SCID, SCTime, timeSource,
  OBCTemp, battTemp, battVolt, battCurrent,
  chargeCurrent, antDep, dataPending,
  rebootCnt, rails1, rails2, rails3,
  rails4, rails5, rails6, RXTemp, TXTemp,
  PATemp, RXNoiseFloor
)
VALUES
  (
    28, 28242, 16962, '28/01/2020 10:00',
    0, 17, 22, 5, 4053, 5209, 1, 6411, 100,
    0, 1, 0, 1, 1, 1, 21,-2, 4, 993
  );
/* INSERT QUERY */
INSERT INTO STATUS(
  packID, seqStat, SCID, SCTime, timeSource,
  OBCTemp, battTemp, battVolt, battCurrent,
  chargeCurrent, antDep, dataPending,
  rebootCnt, rails1, rails2, rails3,
  rails4, rails5, rails6, RXTemp, TXTemp,
  PATemp, RXNoiseFloor
)
VALUES
  (
    29, 23732, 16962, '29/01/2020 10:00',
    0, 3,-4, 5, 4955, 6042, 1, 35590, 105,
    0, 0, 0, 0, 1, 1,-6,-13,-8, 389
  );
/* INSERT QUERY */
INSERT INTO STATUS(
  packID, seqStat, SCID, SCTime, timeSource,
  OBCTemp, battTemp, battVolt, battCurrent,
  chargeCurrent, antDep, dataPending,
  rebootCnt, rails1, rails2, rails3,
  rails4, rails5, rails6, RXTemp, TXTemp,
  PATemp, RXNoiseFloor
)
VALUES
  (
    30, 42499, 16962, '30/01/2020 10:00',
    0,-6,-21, 2, 8069, 8566, 1, 42712, 217,
    0, 1, 1, 1, 0, 1, 16,-17, 6, 349
  );
/* INSERT QUERY */
INSERT INTO STATUS(
  packID, seqStat, SCID, SCTime, timeSource,
  OBCTemp, battTemp, battVolt, battCurrent,
  chargeCurrent, antDep, dataPending,
  rebootCnt, rails1, rails2, rails3,
  rails4, rails5, rails6, RXTemp, TXTemp,
  PATemp, RXNoiseFloor
)
VALUES
  (
    31, 26638, 16962, '31/01/2020 10:00',
    0, 8,-22, 0, 6944, 8352, 1, 37490, 149,
    0, 0, 0, 1, 1, 0, 14, 18, 11, 82
  );
/* INSERT QUERY */
INSERT INTO STATUS(
  packID, seqStat, SCID, SCTime, timeSource,
  OBCTemp, battTemp, battVolt, battCurrent,
  chargeCurrent, antDep, dataPending,
  rebootCnt, rails1, rails2, rails3,
  rails4, rails5, rails6, RXTemp, TXTemp,
  PATemp, RXNoiseFloor
)
VALUES
  (
    32, 56660, 16962, '01/02/2020 10:00',
    0,-6, 10, 3, 5984, 1163, 1, 38247, 145,
    0, 1, 1, 1, 0, 0,-21,-12, 1, 899
  );
/* INSERT QUERY */
INSERT INTO STATUS(
  packID, seqStat, SCID, SCTime, timeSource,
  OBCTemp, battTemp, battVolt, battCurrent,
  chargeCurrent, antDep, dataPending,
  rebootCnt, rails1, rails2, rails3,
  rails4, rails5, rails6, RXTemp, TXTemp,
  PATemp, RXNoiseFloor
)
VALUES
  (
    33, 5308, 16962, '02/02/2020 10:00',
    0, 1,-9, 5, 6269, 5011, 1, 14388, 182,
    1, 1, 1, 0, 1, 1,-8, 18,-14, 527
  );
/* INSERT QUERY */
INSERT INTO STATUS(
  packID, seqStat, SCID, SCTime, timeSource,
  OBCTemp, battTemp, battVolt, battCurrent,
  chargeCurrent, antDep, dataPending,
  rebootCnt, rails1, rails2, rails3,
  rails4, rails5, rails6, RXTemp, TXTemp,
  PATemp, RXNoiseFloor
)
VALUES
  (
    34, 22971, 16962, '03/02/2020 10:00',
    0,-1, 19, 0, 3518, 4854, 1, 2034, 30,
    0, 0, 1, 0, 1, 1, 8, 2, 6, 168
  );
/* INSERT QUERY */
INSERT INTO STATUS(
  packID, seqStat, SCID, SCTime, timeSource,
  OBCTemp, battTemp, battVolt, battCurrent,
  chargeCurrent, antDep, dataPending,
  rebootCnt, rails1, rails2, rails3,
  rails4, rails5, rails6, RXTemp, TXTemp,
  PATemp, RXNoiseFloor
)
VALUES
  (
    35, 54586, 16962, '04/02/2020 10:00',
    1, 11,-2, 4, 5504, 3001, 1, 13695, 197,
    1, 0, 0, 1, 0, 1, 3, 21, 9, 488
  );
/* INSERT QUERY */
INSERT INTO STATUS(
  packID, seqStat, SCID, SCTime, timeSource,
  OBCTemp, battTemp, battVolt, battCurrent,
  chargeCurrent, antDep, dataPending,
  rebootCnt, rails1, rails2, rails3,
  rails4, rails5, rails6, RXTemp, TXTemp,
  PATemp, RXNoiseFloor
)
VALUES
  (
    36, 31311, 16962, '05/02/2020 10:00',
    1,-24,-16, 2, 3307, 2454, 1, 17602,
    87, 0, 0, 0, 1, 1, 1,-3,-22,-15, 374
  );
/* INSERT QUERY */
INSERT INTO STATUS(
  packID, seqStat, SCID, SCTime, timeSource,
  OBCTemp, battTemp, battVolt, battCurrent,
  chargeCurrent, antDep, dataPending,
  rebootCnt, rails1, rails2, rails3,
  rails4, rails5, rails6, RXTemp, TXTemp,
  PATemp, RXNoiseFloor
)
VALUES
  (
    37, 8615, 16962, '06/02/2020 10:00',
    1, 21, 18, 0, 5087, 6539, 1, 55148, 102,
    0, 0, 0, 1, 0, 0, 5, 2, 9, 769
  );
/* INSERT QUERY */
INSERT INTO STATUS(
  packID, seqStat, SCID, SCTime, timeSource,
  OBCTemp, battTemp, battVolt, battCurrent,
  chargeCurrent, antDep, dataPending,
  rebootCnt, rails1, rails2, rails3,
  rails4, rails5, rails6, RXTemp, TXTemp,
  PATemp, RXNoiseFloor
)
VALUES
  (
    38, 3193, 16962, '07/02/2020 10:00',
    1, 6,-15, 5, 3374, 7957, 1, 43112, 214,
    0, 0, 0, 0, 0, 1, 5,-12,-16, 857
  );
/* INSERT QUERY */
INSERT INTO STATUS(
  packID, seqStat, SCID, SCTime, timeSource,
  OBCTemp, battTemp, battVolt, battCurrent,
  chargeCurrent, antDep, dataPending,
  rebootCnt, rails1, rails2, rails3,
  rails4, rails5, rails6, RXTemp, TXTemp,
  PATemp, RXNoiseFloor
)
VALUES
  (
    39, 6607, 16962, '08/02/2020 10:00',
    1, 4, 19, 3, 5510, 7200, 1, 56809, 112,
    1, 1, 1, 0, 1, 1,-1, 0, 12, 615
  );
/* INSERT QUERY */
INSERT INTO STATUS(
  packID, seqStat, SCID, SCTime, timeSource,
  OBCTemp, battTemp, battVolt, battCurrent,
  chargeCurrent, antDep, dataPending,
  rebootCnt, rails1, rails2, rails3,
  rails4, rails5, rails6, RXTemp, TXTemp,
  PATemp, RXNoiseFloor
)
VALUES
  (
    40, 3086, 16962, '09/02/2020 10:00',
    1, 18,-6, 5, 384, 1974, 1, 64831, 145,
    0, 1, 1, 1, 0, 0, 23,-16, 25, 544
  );
/* INSERT QUERY */
INSERT INTO STATUS(
  packID, seqStat, SCID, SCTime, timeSource,
  OBCTemp, battTemp, battVolt, battCurrent,
  chargeCurrent, antDep, dataPending,
  rebootCnt, rails1, rails2, rails3,
  rails4, rails5, rails6, RXTemp, TXTemp,
  PATemp, RXNoiseFloor
)
VALUES
  (
    41, 40501, 16962, '10/02/2020 10:00',
    1, 12,-24, 2, 6484, 1545, 1, 65315, 251,
    0, 1, 1, 1, 1, 0,-11, 15,-12, 912
  );
/* INSERT QUERY */
INSERT INTO STATUS(
  packID, seqStat, SCID, SCTime, timeSource,
  OBCTemp, battTemp, battVolt, battCurrent,
  chargeCurrent, antDep, dataPending,
  rebootCnt, rails1, rails2, rails3,
  rails4, rails5, rails6, RXTemp, TXTemp,
  PATemp, RXNoiseFloor
)
VALUES
  (
    42, 43587, 16962, '11/02/2020 10:00',
    1,-9,-11, 5, 183, 6841, 1, 16453, 127,
    0, 0, 0, 1, 0, 1, 16, 24, 0, 757
  );
/* INSERT QUERY */
INSERT INTO STATUS(
  packID, seqStat, SCID, SCTime, timeSource,
  OBCTemp, battTemp, battVolt, battCurrent,
  chargeCurrent, antDep, dataPending,
  rebootCnt, rails1, rails2, rails3,
  rails4, rails5, rails6, RXTemp, TXTemp,
  PATemp, RXNoiseFloor
)
VALUES
  (
    43, 5081, 16962, '12/02/2020 10:00',
    1,-24, 24, 3, 9025, 3151, 1, 7753, 152,
    1, 0, 1, 1, 0, 0,-18, 13,-17, 183
  );
/* INSERT QUERY */
INSERT INTO STATUS(
  packID, seqStat, SCID, SCTime, timeSource,
  OBCTemp, battTemp, battVolt, battCurrent,
  chargeCurrent, antDep, dataPending,
  rebootCnt, rails1, rails2, rails3,
  rails4, rails5, rails6, RXTemp, TXTemp,
  PATemp, RXNoiseFloor
)
VALUES
  (
    44, 6147, 16962, '13/02/2020 10:00',
    1,-8,-22, 5, 8063, 2232, 1, 57169, 93,
    1, 0, 1, 1, 0, 0, 18, 20,-22, 20
  );
/* INSERT QUERY */
INSERT INTO STATUS(
  packID, seqStat, SCID, SCTime, timeSource,
  OBCTemp, battTemp, battVolt, battCurrent,
  chargeCurrent, antDep, dataPending,
  rebootCnt, rails1, rails2, rails3,
  rails4, rails5, rails6, RXTemp, TXTemp,
  PATemp, RXNoiseFloor
)
VALUES
  (
    45, 25268, 16962, '14/02/2020 10:00',
    1,-12,-10, 4, 1447, 8303, 1, 42764,
    12, 1, 1, 1, 0, 1, 0,-4, 16,-10, 262
  );
/* INSERT QUERY */
INSERT INTO STATUS(
  packID, seqStat, SCID, SCTime, timeSource,
  OBCTemp, battTemp, battVolt, battCurrent,
  chargeCurrent, antDep, dataPending,
  rebootCnt, rails1, rails2, rails3,
  rails4, rails5, rails6, RXTemp, TXTemp,
  PATemp, RXNoiseFloor
)
VALUES
  (
    46, 45432, 16962, '15/02/2020 10:00',
    1,-6,-2, 3, 4475, 7564, 1, 16978, 134,
    0, 1, 1, 0, 0, 1, 9,-6,-11, 9
  );
/* INSERT QUERY */
INSERT INTO STATUS(
  packID, seqStat, SCID, SCTime, timeSource,
  OBCTemp, battTemp, battVolt, battCurrent,
  chargeCurrent, antDep, dataPending,
  rebootCnt, rails1, rails2, rails3,
  rails4, rails5, rails6, RXTemp, TXTemp,
  PATemp, RXNoiseFloor
)
VALUES
  (
    47, 44841, 16962, '16/02/2020 10:00',
    1, 19,-9, 1, 7959, 9308, 1, 17787, 3,
    0, 0, 0, 0, 1, 1,-14, 8,-21, 223
  );
/* INSERT QUERY */
INSERT INTO STATUS(
  packID, seqStat, SCID, SCTime, timeSource,
  OBCTemp, battTemp, battVolt, battCurrent,
  chargeCurrent, antDep, dataPending,
  rebootCnt, rails1, rails2, rails3,
  rails4, rails5, rails6, RXTemp, TXTemp,
  PATemp, RXNoiseFloor
)
VALUES
  (
    48, 41459, 16962, '17/02/2020 10:00',
    1, 0,-3, 2, 3626, 1529, 1, 42206, 132,
    0, 0, 0, 0, 0, 0, 5, 5,-10, 421
  );
/* INSERT QUERY */
INSERT INTO STATUS(
  packID, seqStat, SCID, SCTime, timeSource,
  OBCTemp, battTemp, battVolt, battCurrent,
  chargeCurrent, antDep, dataPending,
  rebootCnt, rails1, rails2, rails3,
  rails4, rails5, rails6, RXTemp, TXTemp,
  PATemp, RXNoiseFloor
)
VALUES
  (
    49, 45873, 16962, '18/02/2020 10:00',
    1,-18, 6, 1, 2178, 6666, 1, 12656, 164,
    0, 1, 1, 1, 1, 0,-11,-1,-13, 24
  );
/* INSERT QUERY */
INSERT INTO STATUS(
  packID, seqStat, SCID, SCTime, timeSource,
  OBCTemp, battTemp, battVolt, battCurrent,
  chargeCurrent, antDep, dataPending,
  rebootCnt, rails1, rails2, rails3,
  rails4, rails5, rails6, RXTemp, TXTemp,
  PATemp, RXNoiseFloor
)
VALUES
  (
    50, 46298, 16962, '19/02/2020 10:00',
    1, 11,-5, 4, 432, 5693, 1, 62895, 195,
    1, 1, 1, 0, 1, 1, 15,-13,-16, 847
  );
/* INSERT QUERY */
INSERT INTO STATUS(
  packID, seqStat, SCID, SCTime, timeSource,
  OBCTemp, battTemp, battVolt, battCurrent,
  chargeCurrent, antDep, dataPending,
  rebootCnt, rails1, rails2, rails3,
  rails4, rails5, rails6, RXTemp, TXTemp,
  PATemp, RXNoiseFloor
)
VALUES
  (
    51, 34623, 16962, '20/02/2020 10:00',
    1, 25, 8, 4, 1366, 3911, 1, 37354, 198,
    1, 1, 0, 1, 0, 1, 7,-8,-3, 380
  );
/* INSERT QUERY */
INSERT INTO STATUS(
  packID, seqStat, SCID, SCTime, timeSource,
  OBCTemp, battTemp, battVolt, battCurrent,
  chargeCurrent, antDep, dataPending,
  rebootCnt, rails1, rails2, rails3,
  rails4, rails5, rails6, RXTemp, TXTemp,
  PATemp, RXNoiseFloor
)
VALUES
  (
    52, 16663, 16962, '21/02/2020 10:00',
    1, 7,-3, 1, 5485, 9841, 1, 11725, 13,
    0, 0, 1, 0, 1, 0, 16, 4, 11, 205
  );
/* INSERT QUERY */
INSERT INTO STATUS(
  packID, seqStat, SCID, SCTime, timeSource,
  OBCTemp, battTemp, battVolt, battCurrent,
  chargeCurrent, antDep, dataPending,
  rebootCnt, rails1, rails2, rails3,
  rails4, rails5, rails6, RXTemp, TXTemp,
  PATemp, RXNoiseFloor
)
VALUES
  (
    53, 42045, 16962, '22/02/2020 10:00',
    1, 9,-12, 5, 7933, 2791, 1, 25118, 141,
    1, 0, 0, 1, 1, 0,-17,-1,-20, 175
  );
/* INSERT QUERY */
INSERT INTO STATUS(
  packID, seqStat, SCID, SCTime, timeSource,
  OBCTemp, battTemp, battVolt, battCurrent,
  chargeCurrent, antDep, dataPending,
  rebootCnt, rails1, rails2, rails3,
  rails4, rails5, rails6, RXTemp, TXTemp,
  PATemp, RXNoiseFloor
)
VALUES
  (
    54, 10000, 16962, '23/02/2020 10:00',
    1,-22, 10, 0, 1495, 9380, 1, 63673, 1,
    0, 0, 1, 1, 0, 1, 20,-21,-17, 872
  );
/* INSERT QUERY */
INSERT INTO STATUS(
  packID, seqStat, SCID, SCTime, timeSource,
  OBCTemp, battTemp, battVolt, battCurrent,
  chargeCurrent, antDep, dataPending,
  rebootCnt, rails1, rails2, rails3,
  rails4, rails5, rails6, RXTemp, TXTemp,
  PATemp, RXNoiseFloor
)
VALUES
  (
    55, 62921, 16962, '24/02/2020 10:00',
    1,-4,-2, 0, 1721, 3752, 1, 54400, 124,
    0, 0, 0, 1, 1, 1, 24, 20,-25, 281
  );
/* INSERT QUERY */
INSERT INTO STATUS(
  packID, seqStat, SCID, SCTime, timeSource,
  OBCTemp, battTemp, battVolt, battCurrent,
  chargeCurrent, antDep, dataPending,
  rebootCnt, rails1, rails2, rails3,
  rails4, rails5, rails6, RXTemp, TXTemp,
  PATemp, RXNoiseFloor
)
VALUES
  (
    56, 1210, 16962, '25/02/2020 10:00',
    1,-3, 14, 5, 6507, 343, 1, 22577, 188,
    0, 1, 1, 0, 1, 1, 14, 18,-7, 501
  );
/* INSERT QUERY */
INSERT INTO STATUS(
  packID, seqStat, SCID, SCTime, timeSource,
  OBCTemp, battTemp, battVolt, battCurrent,
  chargeCurrent, antDep, dataPending,
  rebootCnt, rails1, rails2, rails3,
  rails4, rails5, rails6, RXTemp, TXTemp,
  PATemp, RXNoiseFloor
)
VALUES
  (
    57, 38571, 16962, '26/02/2020 10:00',
    1, 13,-10, 3, 7638, 2496, 1, 4730, 178,
    0, 1, 1, 1, 0, 0,-17, 21,-25, 441
  );
/* INSERT QUERY */
INSERT INTO STATUS(
  packID, seqStat, SCID, SCTime, timeSource,
  OBCTemp, battTemp, battVolt, battCurrent,
  chargeCurrent, antDep, dataPending,
  rebootCnt, rails1, rails2, rails3,
  rails4, rails5, rails6, RXTemp, TXTemp,
  PATemp, RXNoiseFloor
)
VALUES
  (
    58, 42258, 16962, '27/02/2020 10:00',
    1,-23,-24, 5, 7420, 2967, 1, 53683,
    23, 1, 1, 0, 1, 1, 1, 3,-16, 14, 539
  );
/* INSERT QUERY */
INSERT INTO STATUS(
  packID, seqStat, SCID, SCTime, timeSource,
  OBCTemp, battTemp, battVolt, battCurrent,
  chargeCurrent, antDep, dataPending,
  rebootCnt, rails1, rails2, rails3,
  rails4, rails5, rails6, RXTemp, TXTemp,
  PATemp, RXNoiseFloor
)
VALUES
  (
    59, 51730, 16962, '28/02/2020 10:00',
    1,-4,-11, 3, 4536, 6496, 1, 15676, 240,
    1, 1, 0, 1, 1, 1,-2,-22, 8, 555
  );
/* INSERT QUERY */
INSERT INTO STATUS(
  packID, seqStat, SCID, SCTime, timeSource,
  OBCTemp, battTemp, battVolt, battCurrent,
  chargeCurrent, antDep, dataPending,
  rebootCnt, rails1, rails2, rails3,
  rails4, rails5, rails6, RXTemp, TXTemp,
  PATemp, RXNoiseFloor
)
VALUES
  (
    60, 51487, 16962, '29/02/2020 10:00',
    1,-17, 19, 2, 2808, 9139, 1, 63614, 139,
    0, 1, 1, 0, 1, 0, 7, 6, 6, 372
  );
/* INSERT QUERY */
INSERT INTO STATUS(
  packID, seqStat, SCID, SCTime, timeSource,
  OBCTemp, battTemp, battVolt, battCurrent,
  chargeCurrent, antDep, dataPending,
  rebootCnt, rails1, rails2, rails3,
  rails4, rails5, rails6, RXTemp, TXTemp,
  PATemp, RXNoiseFloor
)
VALUES
  (
    61, 19567, 16962, '01/03/2020 10:00',
    1, 22, 1, 3, 5763, 1389, 1, 51024, 51,
    0, 1, 0, 0, 0, 0,-12,-19,-20, 116
  );
/* INSERT QUERY */
INSERT INTO STATUS(
  packID, seqStat, SCID, SCTime, timeSource,
  OBCTemp, battTemp, battVolt, battCurrent,
  chargeCurrent, antDep, dataPending,
  rebootCnt, rails1, rails2, rails3,
  rails4, rails5, rails6, RXTemp, TXTemp,
  PATemp, RXNoiseFloor
)
VALUES
  (
    62, 41929, 16962, '02/03/2020 10:00',
    1, 20,-24, 1, 2288, 1125, 1, 36098, 4,
    1, 1, 1, 1, 0, 1,-25,-1, 4, 781
  );
/* INSERT QUERY */
INSERT INTO STATUS(
  packID, seqStat, SCID, SCTime, timeSource,
  OBCTemp, battTemp, battVolt, battCurrent,
  chargeCurrent, antDep, dataPending,
  rebootCnt, rails1, rails2, rails3,
  rails4, rails5, rails6, RXTemp, TXTemp,
  PATemp, RXNoiseFloor
)
VALUES
  (
    63, 25026, 16962, '03/03/2020 10:00',
    1,-5,-18, 2, 5786, 5651, 1, 48281, 245,
    1, 1, 1, 1, 1, 1, 1, 5,-8, 368
  );
/* INSERT QUERY */
INSERT INTO STATUS(
  packID, seqStat, SCID, SCTime, timeSource,
  OBCTemp, battTemp, battVolt, battCurrent,
  chargeCurrent, antDep, dataPending,
  rebootCnt, rails1, rails2, rails3,
  rails4, rails5, rails6, RXTemp, TXTemp,
  PATemp, RXNoiseFloor
)
VALUES
  (
    64, 25133, 16962, '04/03/2020 10:00',
    1, 7, 10, 3, 3977, 1814, 1, 3574, 100,
    1, 1, 1, 0, 1, 1, 15,-15, 6, 546
  );
/* INSERT QUERY */
INSERT INTO STATUS(
  packID, seqStat, SCID, SCTime, timeSource,
  OBCTemp, battTemp, battVolt, battCurrent,
  chargeCurrent, antDep, dataPending,
  rebootCnt, rails1, rails2, rails3,
  rails4, rails5, rails6, RXTemp, TXTemp,
  PATemp, RXNoiseFloor
)
VALUES
  (
    65, 34512, 16962, '05/03/2020 10:00',
    1, 9,-6, 1, 9040, 9489, 1, 21697, 68,
    0, 0, 0, 1, 0, 0, 24, 25, 21, 731
  );
/* INSERT QUERY */
INSERT INTO STATUS(
  packID, seqStat, SCID, SCTime, timeSource,
  OBCTemp, battTemp, battVolt, battCurrent,
  chargeCurrent, antDep, dataPending,
  rebootCnt, rails1, rails2, rails3,
  rails4, rails5, rails6, RXTemp, TXTemp,
  PATemp, RXNoiseFloor
)
VALUES
  (
    66, 35274, 16962, '06/03/2020 10:00',
    1, 4, 24, 5, 2169, 8577, 1, 55823, 29,
    0, 1, 0, 0, 0, 0, 12,-5,-6, 818
  );
/* INSERT QUERY */
INSERT INTO STATUS(
  packID, seqStat, SCID, SCTime, timeSource,
  OBCTemp, battTemp, battVolt, battCurrent,
  chargeCurrent, antDep, dataPending,
  rebootCnt, rails1, rails2, rails3,
  rails4, rails5, rails6, RXTemp, TXTemp,
  PATemp, RXNoiseFloor
)
VALUES
  (
    67, 62525, 16962, '07/03/2020 10:00',
    1, 14,-11, 2, 389, 3549, 1, 35306, 26,
    1, 1, 1, 1, 1, 0, 13,-21,-5, 930
  );
/* INSERT QUERY */
INSERT INTO STATUS(
  packID, seqStat, SCID, SCTime, timeSource,
  OBCTemp, battTemp, battVolt, battCurrent,
  chargeCurrent, antDep, dataPending,
  rebootCnt, rails1, rails2, rails3,
  rails4, rails5, rails6, RXTemp, TXTemp,
  PATemp, RXNoiseFloor
)
VALUES
  (
    68, 28947, 16962, '08/03/2020 10:00',
    1, 4,-8, 2, 5009, 8244, 1, 38058, 150,
    1, 1, 1, 1, 1, 1,-20,-3,-8, 173
  );
/* INSERT QUERY */
INSERT INTO STATUS(
  packID, seqStat, SCID, SCTime, timeSource,
  OBCTemp, battTemp, battVolt, battCurrent,
  chargeCurrent, antDep, dataPending,
  rebootCnt, rails1, rails2, rails3,
  rails4, rails5, rails6, RXTemp, TXTemp,
  PATemp, RXNoiseFloor
)
VALUES
  (
    69, 31356, 16962, '09/03/2020 10:00',
    1,-8,-4, 0, 659, 3310, 1, 55861, 41,
    0, 1, 0, 1, 0, 1, 14, 9, 16, 815
  );
/* INSERT QUERY */
INSERT INTO STATUS(
  packID, seqStat, SCID, SCTime, timeSource,
  OBCTemp, battTemp, battVolt, battCurrent,
  chargeCurrent, antDep, dataPending,
  rebootCnt, rails1, rails2, rails3,
  rails4, rails5, rails6, RXTemp, TXTemp,
  PATemp, RXNoiseFloor
)
VALUES
  (
    70, 43437, 16962, '10/03/2020 10:00',
    1, 3, 24, 2, 6684, 4658, 1, 31252, 152,
    0, 0, 0, 1, 0, 0, 11,-25,-23, 708
  );
/* INSERT QUERY */
INSERT INTO STATUS(
  packID, seqStat, SCID, SCTime, timeSource,
  OBCTemp, battTemp, battVolt, battCurrent,
  chargeCurrent, antDep, dataPending,
  rebootCnt, rails1, rails2, rails3,
  rails4, rails5, rails6, RXTemp, TXTemp,
  PATemp, RXNoiseFloor
)
VALUES
  (
    71, 5337, 16962, '11/03/2020 10:00',
    1, 20,-13, 1, 7074, 309, 1, 5775, 127,
    0, 0, 0, 0, 0, 0,-7, 21, 8, 651
  );
/* INSERT QUERY */
INSERT INTO STATUS(
  packID, seqStat, SCID, SCTime, timeSource,
  OBCTemp, battTemp, battVolt, battCurrent,
  chargeCurrent, antDep, dataPending,
  rebootCnt, rails1, rails2, rails3,
  rails4, rails5, rails6, RXTemp, TXTemp,
  PATemp, RXNoiseFloor
)
VALUES
  (
    72, 7471, 16962, '12/03/2020 10:00',
    1,-23, 20, 4, 2461, 2944, 1, 64903, 92,
    0, 1, 0, 0, 1, 0, 17,-22, 9, 675
  );
/* INSERT QUERY */
INSERT INTO STATUS(
  packID, seqStat, SCID, SCTime, timeSource,
  OBCTemp, battTemp, battVolt, battCurrent,
  chargeCurrent, antDep, dataPending,
  rebootCnt, rails1, rails2, rails3,
  rails4, rails5, rails6, RXTemp, TXTemp,
  PATemp, RXNoiseFloor
)
VALUES
  (
    73, 25166, 16962, '13/03/2020 10:00',
    1, 4,-11, 4, 9045, 5538, 1, 39656, 70,
    1, 1, 1, 1, 1, 0,-10,-19,-16, 995
  );
/* INSERT QUERY */
INSERT INTO STATUS(
  packID, seqStat, SCID, SCTime, timeSource,
  OBCTemp, battTemp, battVolt, battCurrent,
  chargeCurrent, antDep, dataPending,
  rebootCnt, rails1, rails2, rails3,
  rails4, rails5, rails6, RXTemp, TXTemp,
  PATemp, RXNoiseFloor
)
VALUES
  (
    74, 32232, 16962, '14/03/2020 10:00',
    1, 2, 11, 5, 1231, 8866, 1, 5625, 234,
    0, 0, 0, 1, 0, 1,-10,-1,-24, 469
  );
/* INSERT QUERY */
INSERT INTO STATUS(
  packID, seqStat, SCID, SCTime, timeSource,
  OBCTemp, battTemp, battVolt, battCurrent,
  chargeCurrent, antDep, dataPending,
  rebootCnt, rails1, rails2, rails3,
  rails4, rails5, rails6, RXTemp, TXTemp,
  PATemp, RXNoiseFloor
)
VALUES
  (
    75, 2194, 16962, '15/03/2020 10:00',
    1, 20, 11, 2, 832, 6969, 1, 51615, 181,
    1, 1, 0, 1, 1, 0, 0, 15,-17, 267
  );
/* INSERT QUERY */
INSERT INTO STATUS(
  packID, seqStat, SCID, SCTime, timeSource,
  OBCTemp, battTemp, battVolt, battCurrent,
  chargeCurrent, antDep, dataPending,
  rebootCnt, rails1, rails2, rails3,
  rails4, rails5, rails6, RXTemp, TXTemp,
  PATemp, RXNoiseFloor
)
VALUES
  (
    76, 34175, 16962, '16/03/2020 10:00',
    1, 25, 18, 1, 4684, 934, 1, 46018, 111,
    0, 0, 1, 1, 0, 0, 18,-15,-13, 991
  );
/* INSERT QUERY */
INSERT INTO STATUS(
  packID, seqStat, SCID, SCTime, timeSource,
  OBCTemp, battTemp, battVolt, battCurrent,
  chargeCurrent, antDep, dataPending,
  rebootCnt, rails1, rails2, rails3,
  rails4, rails5, rails6, RXTemp, TXTemp,
  PATemp, RXNoiseFloor
)
VALUES
  (
    77, 32487, 16962, '17/03/2020 10:00',
    1,-15, 16, 2, 6417, 2463, 1, 13638, 169,
    1, 1, 0, 1, 0, 1, 9,-9,-6, 15
  );
/* INSERT QUERY */
INSERT INTO STATUS(
  packID, seqStat, SCID, SCTime, timeSource,
  OBCTemp, battTemp, battVolt, battCurrent,
  chargeCurrent, antDep, dataPending,
  rebootCnt, rails1, rails2, rails3,
  rails4, rails5, rails6, RXTemp, TXTemp,
  PATemp, RXNoiseFloor
)
VALUES
  (
    78, 54308, 16962, '18/03/2020 10:00',
    1,-15, 6, 2, 2255, 5188, 1, 8913, 82,
    0, 1, 0, 0, 1, 1,-12, 1,-8, 368
  );
/* INSERT QUERY */
INSERT INTO STATUS(
  packID, seqStat, SCID, SCTime, timeSource,
  OBCTemp, battTemp, battVolt, battCurrent,
  chargeCurrent, antDep, dataPending,
  rebootCnt, rails1, rails2, rails3,
  rails4, rails5, rails6, RXTemp, TXTemp,
  PATemp, RXNoiseFloor
)
VALUES
  (
    79, 8125, 16962, '19/03/2020 10:00',
    1, 18,-13, 5, 1997, 639, 1, 770, 140,
    1, 1, 1, 1, 1, 0, 20,-17, 4, 984
  );
/* INSERT QUERY */
INSERT INTO STATUS(
  packID, seqStat, SCID, SCTime, timeSource,
  OBCTemp, battTemp, battVolt, battCurrent,
  chargeCurrent, antDep, dataPending,
  rebootCnt, rails1, rails2, rails3,
  rails4, rails5, rails6, RXTemp, TXTemp,
  PATemp, RXNoiseFloor
)
VALUES
  (
    80, 16423, 16962, '20/03/2020 10:00',
    1,-22,-5, 2, 4831, 5541, 1, 6871, 216,
    0, 0, 1, 1, 1, 0, 0, 15, 19, 114
  );
/* INSERT QUERY */
INSERT INTO STATUS(
  packID, seqStat, SCID, SCTime, timeSource,
  OBCTemp, battTemp, battVolt, battCurrent,
  chargeCurrent, antDep, dataPending,
  rebootCnt, rails1, rails2, rails3,
  rails4, rails5, rails6, RXTemp, TXTemp,
  PATemp, RXNoiseFloor
)
VALUES
  (
    81, 34582, 16962, '21/03/2020 10:00',
    1,-22,-8, 0, 3225, 9580, 1, 7525, 235,
    1, 1, 0, 1, 1, 0, 18,-1, 23, 341
  );
/* INSERT QUERY */
INSERT INTO STATUS(
  packID, seqStat, SCID, SCTime, timeSource,
  OBCTemp, battTemp, battVolt, battCurrent,
  chargeCurrent, antDep, dataPending,
  rebootCnt, rails1, rails2, rails3,
  rails4, rails5, rails6, RXTemp, TXTemp,
  PATemp, RXNoiseFloor
)
VALUES
  (
    82, 26648, 16962, '22/03/2020 10:00',
    1, 3, 22, 1, 6601, 8391, 1, 11461, 171,
    1, 1, 0, 0, 0, 0,-13,-8,-20, 305
  );
/* INSERT QUERY */
INSERT INTO STATUS(
  packID, seqStat, SCID, SCTime, timeSource,
  OBCTemp, battTemp, battVolt, battCurrent,
  chargeCurrent, antDep, dataPending,
  rebootCnt, rails1, rails2, rails3,
  rails4, rails5, rails6, RXTemp, TXTemp,
  PATemp, RXNoiseFloor
)
VALUES
  (
    83, 11300, 16962, '23/03/2020 10:00',
    1,-3, 25, 5, 2447, 3808, 1, 62443, 104,
    0, 0, 1, 1, 0, 1, 24,-8,-17, 491
  );
/* INSERT QUERY */
INSERT INTO STATUS(
  packID, seqStat, SCID, SCTime, timeSource,
  OBCTemp, battTemp, battVolt, battCurrent,
  chargeCurrent, antDep, dataPending,
  rebootCnt, rails1, rails2, rails3,
  rails4, rails5, rails6, RXTemp, TXTemp,
  PATemp, RXNoiseFloor
)
VALUES
  (
    84, 62438, 16962, '24/03/2020 10:00',
    1, 21,-6, 5, 9997, 2184, 1, 51181, 205,
    0, 1, 0, 0, 0, 0,-5,-6,-15, 450
  );
/* INSERT QUERY */
INSERT INTO STATUS(
  packID, seqStat, SCID, SCTime, timeSource,
  OBCTemp, battTemp, battVolt, battCurrent,
  chargeCurrent, antDep, dataPending,
  rebootCnt, rails1, rails2, rails3,
  rails4, rails5, rails6, RXTemp, TXTemp,
  PATemp, RXNoiseFloor
)
VALUES
  (
    85, 44050, 16962, '25/03/2020 10:00',
    1,-25,-21, 1, 4118, 5488, 1, 24270,
    128, 0, 0, 0, 0, 1, 0,-22, 20,-20, 124
  );
/* INSERT QUERY */
INSERT INTO STATUS(
  packID, seqStat, SCID, SCTime, timeSource,
  OBCTemp, battTemp, battVolt, battCurrent,
  chargeCurrent, antDep, dataPending,
  rebootCnt, rails1, rails2, rails3,
  rails4, rails5, rails6, RXTemp, TXTemp,
  PATemp, RXNoiseFloor
)
VALUES
  (
    86, 21004, 16962, '26/03/2020 10:00',
    1,-1,-21, 3, 5575, 5226, 1, 48276, 53,
    0, 1, 0, 0, 0, 0,-24,-17,-1, 441
  );
/* INSERT QUERY */
INSERT INTO STATUS(
  packID, seqStat, SCID, SCTime, timeSource,
  OBCTemp, battTemp, battVolt, battCurrent,
  chargeCurrent, antDep, dataPending,
  rebootCnt, rails1, rails2, rails3,
  rails4, rails5, rails6, RXTemp, TXTemp,
  PATemp, RXNoiseFloor
)
VALUES
  (
    87, 9285, 16962, '27/03/2020 10:00',
    1,-14,-24, 3, 3167, 3079, 1, 3465, 34,
    0, 1, 0, 1, 1, 1,-18, 3, 22, 164
  );
/* INSERT QUERY */
INSERT INTO STATUS(
  packID, seqStat, SCID, SCTime, timeSource,
  OBCTemp, battTemp, battVolt, battCurrent,
  chargeCurrent, antDep, dataPending,
  rebootCnt, rails1, rails2, rails3,
  rails4, rails5, rails6, RXTemp, TXTemp,
  PATemp, RXNoiseFloor
)
VALUES
  (
    88, 43106, 16962, '28/03/2020 10:00',
    1, 20,-14, 2, 5707, 6038, 1, 12879, 142,
    1, 0, 1, 1, 0, 0, 19,-21, 20, 211
  );
/* INSERT QUERY */
INSERT INTO STATUS(
  packID, seqStat, SCID, SCTime, timeSource,
  OBCTemp, battTemp, battVolt, battCurrent,
  chargeCurrent, antDep, dataPending,
  rebootCnt, rails1, rails2, rails3,
  rails4, rails5, rails6, RXTemp, TXTemp,
  PATemp, RXNoiseFloor
)
VALUES
  (
    89, 30952, 16962, '29/03/2020 10:00',
    1, 6, 5, 0, 3612, 6588, 1, 36519, 235,
    0, 0, 0, 0, 0, 0,-25, 16, 10, 501
  );
/* INSERT QUERY */
INSERT INTO STATUS(
  packID, seqStat, SCID, SCTime, timeSource,
  OBCTemp, battTemp, battVolt, battCurrent,
  chargeCurrent, antDep, dataPending,
  rebootCnt, rails1, rails2, rails3,
  rails4, rails5, rails6, RXTemp, TXTemp,
  PATemp, RXNoiseFloor
)
VALUES
  (
    90, 16932, 16962, '30/03/2020 10:00',
    1, 11,-4, 5, 4438, 8970, 1, 3924, 230,
    0, 0, 0, 0, 1, 1,-15,-21,-22, 358
  );
/* INSERT QUERY */
INSERT INTO STATUS(
  packID, seqStat, SCID, SCTime, timeSource,
  OBCTemp, battTemp, battVolt, battCurrent,
  chargeCurrent, antDep, dataPending,
  rebootCnt, rails1, rails2, rails3,
  rails4, rails5, rails6, RXTemp, TXTemp,
  PATemp, RXNoiseFloor
)
VALUES
  (
    91, 65438, 16962, '31/03/2020 10:00',
    1,-25, 13, 3, 7205, 4147, 1, 29667, 0,
    0, 0, 1, 1, 1, 0,-21, 8, 10, 905
  );
/* INSERT QUERY */
INSERT INTO STATUS(
  packID, seqStat, SCID, SCTime, timeSource,
  OBCTemp, battTemp, battVolt, battCurrent,
  chargeCurrent, antDep, dataPending,
  rebootCnt, rails1, rails2, rails3,
  rails4, rails5, rails6, RXTemp, TXTemp,
  PATemp, RXNoiseFloor
)
VALUES
  (
    92, 23272, 16962, '01/04/2020 10:00',
    1, 24,-3, 4, 9443, 1082, 1, 51414, 193,
    1, 0, 1, 1, 1, 0, 11,-9,-18, 139
  );
/* INSERT QUERY */
INSERT INTO STATUS(
  packID, seqStat, SCID, SCTime, timeSource,
  OBCTemp, battTemp, battVolt, battCurrent,
  chargeCurrent, antDep, dataPending,
  rebootCnt, rails1, rails2, rails3,
  rails4, rails5, rails6, RXTemp, TXTemp,
  PATemp, RXNoiseFloor
)
VALUES
  (
    93, 46106, 16962, '02/04/2020 10:00',
    1,-12,-10, 4, 6118, 2435, 1, 24358,
    45, 1, 1, 0, 1, 1, 1,-8,-11,-17, 304
  );
/* INSERT QUERY */
INSERT INTO STATUS(
  packID, seqStat, SCID, SCTime, timeSource,
  OBCTemp, battTemp, battVolt, battCurrent,
  chargeCurrent, antDep, dataPending,
  rebootCnt, rails1, rails2, rails3,
  rails4, rails5, rails6, RXTemp, TXTemp,
  PATemp, RXNoiseFloor
)
VALUES
  (
    94, 47053, 16962, '03/04/2020 10:00',
    1, 0,-23, 1, 1752, 6249, 1, 49662, 136,
    1, 1, 1, 0, 0, 0,-21, 24,-24, 966
  );
/* INSERT QUERY */
INSERT INTO STATUS(
  packID, seqStat, SCID, SCTime, timeSource,
  OBCTemp, battTemp, battVolt, battCurrent,
  chargeCurrent, antDep, dataPending,
  rebootCnt, rails1, rails2, rails3,
  rails4, rails5, rails6, RXTemp, TXTemp,
  PATemp, RXNoiseFloor
)
VALUES
  (
    95, 59805, 16962, '04/04/2020 10:00',
    1,-11,-19, 0, 1001, 6431, 1, 25570,
    32, 0, 0, 1, 0, 1, 0,-1, 8,-10, 629
  );
/* INSERT QUERY */
INSERT INTO STATUS(
  packID, seqStat, SCID, SCTime, timeSource,
  OBCTemp, battTemp, battVolt, battCurrent,
  chargeCurrent, antDep, dataPending,
  rebootCnt, rails1, rails2, rails3,
  rails4, rails5, rails6, RXTemp, TXTemp,
  PATemp, RXNoiseFloor
)
VALUES
  (
    96, 43437, 16962, '05/04/2020 10:00',
    0,-1,-1, 1, 121, 8922, 1, 41453, 130,
    0, 0, 1, 0, 0, 1, 20,-13, 19, 992
  );
/* INSERT QUERY */
INSERT INTO STATUS(
  packID, seqStat, SCID, SCTime, timeSource,
  OBCTemp, battTemp, battVolt, battCurrent,
  chargeCurrent, antDep, dataPending,
  rebootCnt, rails1, rails2, rails3,
  rails4, rails5, rails6, RXTemp, TXTemp,
  PATemp, RXNoiseFloor
)
VALUES
  (
    97, 18265, 16962, '06/04/2020 10:00',
    0, 20,-3, 5, 8967, 2247, 1, 6126, 116,
    0, 1, 0, 0, 1, 1,-22, 13,-16, 926
  );
/* INSERT QUERY */
INSERT INTO STATUS(
  packID, seqStat, SCID, SCTime, timeSource,
  OBCTemp, battTemp, battVolt, battCurrent,
  chargeCurrent, antDep, dataPending,
  rebootCnt, rails1, rails2, rails3,
  rails4, rails5, rails6, RXTemp, TXTemp,
  PATemp, RXNoiseFloor
)
VALUES
  (
    98, 1633, 16962, '07/04/2020 10:00',
    0, 25, 11, 2, 8682, 5718, 1, 31788, 78,
    0, 0, 1, 0, 0, 0, 25,-2,-13, 980
  );
/* INSERT QUERY */
INSERT INTO STATUS(
  packID, seqStat, SCID, SCTime, timeSource,
  OBCTemp, battTemp, battVolt, battCurrent,
  chargeCurrent, antDep, dataPending,
  rebootCnt, rails1, rails2, rails3,
  rails4, rails5, rails6, RXTemp, TXTemp,
  PATemp, RXNoiseFloor
)
VALUES
  (
    99, 52309, 16962, '08/04/2020 10:00',
    0,-7,-15, 4, 5899, 8149, 1, 13351, 72,
    0, 0, 1, 0, 0, 0, 15,-11,-21, 568
  );
/* INSERT QUERY */
INSERT INTO STATUS(
  packID, seqStat, SCID, SCTime, timeSource,
  OBCTemp, battTemp, battVolt, battCurrent,
  chargeCurrent, antDep, dataPending,
  rebootCnt, rails1, rails2, rails3,
  rails4, rails5, rails6, RXTemp, TXTemp,
  PATemp, RXNoiseFloor
)
VALUES
  (
    100, 28652, 16962, '09/04/2020 10:00',
    0, 13,-5, 3, 2908, 114, 1, 11892, 19,
    0, 0, 1, 0, 1, 1,-14, 16,-25, 459
  );

  /* INSERT QUERY */
  INSERT INTO GPS(
    packID, seqPayload, payloadTimeStamp,
    lat, lon, alt, HDOP, VDOP, PDOP, TDOP
  )
  VALUES
    (
      1, 27590, '31/12/2019 10:00',-6, 15,
      200, 724, 2,-868, 281
    );
  /* INSERT QUERY */
  INSERT INTO GPS(
    packID, seqPayload, payloadTimeStamp,
    lat, lon, alt, HDOP, VDOP, PDOP, TDOP
  )
  VALUES
    (
      2, 1136, '01/01/2020 10:00',-25,-175,
      202,-75, 981,-425,-560
    );
  /* INSERT QUERY */
  INSERT INTO GPS(
    packID, seqPayload, payloadTimeStamp,
    lat, lon, alt, HDOP, VDOP, PDOP, TDOP
  )
  VALUES
    (
      3, 11359, '02/01/2020 10:00',-60,
      173, 218,-660,-898, 54,-774
    );
  /* INSERT QUERY */
  INSERT INTO GPS(
    packID, seqPayload, payloadTimeStamp,
    lat, lon, alt, HDOP, VDOP, PDOP, TDOP
  )
  VALUES
    (
      4, 7309, '03/01/2020 10:00', 76,-82,
      124,-893,-863, 726,-771
    );
  /* INSERT QUERY */
  INSERT INTO GPS(
    packID, seqPayload, payloadTimeStamp,
    lat, lon, alt, HDOP, VDOP, PDOP, TDOP
  )
  VALUES
    (
      5, 16806, '04/01/2020 10:00', 86,-56,
      151,-14,-359, 922, 119
    );
  /* INSERT QUERY */
  INSERT INTO GPS(
    packID, seqPayload, payloadTimeStamp,
    lat, lon, alt, HDOP, VDOP, PDOP, TDOP
  )
  VALUES
    (
      6, 1514, '05/01/2020 10:00',-37, 111,
      131,-123,-595,-549, 613
    );
  /* INSERT QUERY */
  INSERT INTO GPS(
    packID, seqPayload, payloadTimeStamp,
    lat, lon, alt, HDOP, VDOP, PDOP, TDOP
  )
  VALUES
    (
      7, 32639, '06/01/2020 10:00', 47, 179,
      155,-18, 212, 173, 607
    );
  /* INSERT QUERY */
  INSERT INTO GPS(
    packID, seqPayload, payloadTimeStamp,
    lat, lon, alt, HDOP, VDOP, PDOP, TDOP
  )
  VALUES
    (
      8, 25164, '07/01/2020 10:00',-51,
      -139, 117, 150,-549, 203,-129
    );
  /* INSERT QUERY */
  INSERT INTO GPS(
    packID, seqPayload, payloadTimeStamp,
    lat, lon, alt, HDOP, VDOP, PDOP, TDOP
  )
  VALUES
    (
      9, 60970, '08/01/2020 10:00',-71,
      112, 127,-574, 66, 169, 918
    );
  /* INSERT QUERY */
  INSERT INTO GPS(
    packID, seqPayload, payloadTimeStamp,
    lat, lon, alt, HDOP, VDOP, PDOP, TDOP
  )
  VALUES
    (
      10, 48878, '09/01/2020 10:00', 44,
      -179, 103, 364, 924,-913,-73
    );
  /* INSERT QUERY */
  INSERT INTO GPS(
    packID, seqPayload, payloadTimeStamp,
    lat, lon, alt, HDOP, VDOP, PDOP, TDOP
  )
  VALUES
    (
      11, 34933, '10/01/2020 10:00', 77,
      40, 182, 549, 90, 197,-565
    );
  /* INSERT QUERY */
  INSERT INTO GPS(
    packID, seqPayload, payloadTimeStamp,
    lat, lon, alt, HDOP, VDOP, PDOP, TDOP
  )
  VALUES
    (
      12, 5765, '11/01/2020 10:00', 39,-30,
      158, 856, 857,-759, 620
    );
  /* INSERT QUERY */
  INSERT INTO GPS(
    packID, seqPayload, payloadTimeStamp,
    lat, lon, alt, HDOP, VDOP, PDOP, TDOP
  )
  VALUES
    (
      13, 37688, '12/01/2020 10:00',-18,
      85, 146,-542, 722,-789,-672
    );
  /* INSERT QUERY */
  INSERT INTO GPS(
    packID, seqPayload, payloadTimeStamp,
    lat, lon, alt, HDOP, VDOP, PDOP, TDOP
  )
  VALUES
    (
      14, 30519, '13/01/2020 10:00',-31,
      173, 216, 770,-624,-892, 544
    );
  /* INSERT QUERY */
  INSERT INTO GPS(
    packID, seqPayload, payloadTimeStamp,
    lat, lon, alt, HDOP, VDOP, PDOP, TDOP
  )
  VALUES
    (
      15, 52774, '14/01/2020 10:00',-46,
      -142, 218, 137, 791, 356,-990
    );
  /* INSERT QUERY */
  INSERT INTO GPS(
    packID, seqPayload, payloadTimeStamp,
    lat, lon, alt, HDOP, VDOP, PDOP, TDOP
  )
  VALUES
    (
      16, 50982, '15/01/2020 10:00', 46,
      8, 166,-861,-636,-413, 956
    );
  /* INSERT QUERY */
  INSERT INTO GPS(
    packID, seqPayload, payloadTimeStamp,
    lat, lon, alt, HDOP, VDOP, PDOP, TDOP
  )
  VALUES
    (
      17, 58503, '16/01/2020 10:00', 67,
      -82, 188,-366,-583,-787,-801
    );
  /* INSERT QUERY */
  INSERT INTO GPS(
    packID, seqPayload, payloadTimeStamp,
    lat, lon, alt, HDOP, VDOP, PDOP, TDOP
  )
  VALUES
    (
      18, 60287, '17/01/2020 10:00',-41,
      170, 233, 390,-22,-119,-613
    );
  /* INSERT QUERY */
  INSERT INTO GPS(
    packID, seqPayload, payloadTimeStamp,
    lat, lon, alt, HDOP, VDOP, PDOP, TDOP
  )
  VALUES
    (
      19, 9028, '18/01/2020 10:00', 65, 116,
      134,-757, 517,-45, 130
    );
  /* INSERT QUERY */
  INSERT INTO GPS(
    packID, seqPayload, payloadTimeStamp,
    lat, lon, alt, HDOP, VDOP, PDOP, TDOP
  )
  VALUES
    (
      20, 39175, '19/01/2020 10:00', 25,
      -71, 173, 216,-771, 496, 115
    );
  /* INSERT QUERY */
  INSERT INTO GPS(
    packID, seqPayload, payloadTimeStamp,
    lat, lon, alt, HDOP, VDOP, PDOP, TDOP
  )
  VALUES
    (
      21, 49623, '20/01/2020 10:00', 78,
      -164, 178, 217,-507,-83,-123
    );
  /* INSERT QUERY */
  INSERT INTO GPS(
    packID, seqPayload, payloadTimeStamp,
    lat, lon, alt, HDOP, VDOP, PDOP, TDOP
  )
  VALUES
    (
      22, 49157, '21/01/2020 10:00', 50,
      39, 151,-345, 518,-768, 711
    );
  /* INSERT QUERY */
  INSERT INTO GPS(
    packID, seqPayload, payloadTimeStamp,
    lat, lon, alt, HDOP, VDOP, PDOP, TDOP
  )
  VALUES
    (
      23, 65466, '22/01/2020 10:00',-4,
      17, 182,-367, 486, 686,-568
    );
  /* INSERT QUERY */
  INSERT INTO GPS(
    packID, seqPayload, payloadTimeStamp,
    lat, lon, alt, HDOP, VDOP, PDOP, TDOP
  )
  VALUES
    (
      24, 31968, '23/01/2020 10:00', 74,
      -67, 219, 406, 289, 731, 784
    );
  /* INSERT QUERY */
  INSERT INTO GPS(
    packID, seqPayload, payloadTimeStamp,
    lat, lon, alt, HDOP, VDOP, PDOP, TDOP
  )
  VALUES
    (
      25, 38622, '24/01/2020 10:00',-82,
      101, 201, 283, 337,-778, 708
    );
  /* INSERT QUERY */
  INSERT INTO GPS(
    packID, seqPayload, payloadTimeStamp,
    lat, lon, alt, HDOP, VDOP, PDOP, TDOP
  )
  VALUES
    (
      26, 46121, '25/01/2020 10:00',-42,
      160, 192, 834,-339,-122,-391
    );
  /* INSERT QUERY */
  INSERT INTO GPS(
    packID, seqPayload, payloadTimeStamp,
    lat, lon, alt, HDOP, VDOP, PDOP, TDOP
  )
  VALUES
    (
      27, 59355, '26/01/2020 10:00',-9,
      72, 172,-328, 734, 13, 879
    );
  /* INSERT QUERY */
  INSERT INTO GPS(
    packID, seqPayload, payloadTimeStamp,
    lat, lon, alt, HDOP, VDOP, PDOP, TDOP
  )
  VALUES
    (
      28, 33112, '27/01/2020 10:00', 80,
      -42, 248, 971, 439, 757,-311
    );
  /* INSERT QUERY */
  INSERT INTO GPS(
    packID, seqPayload, payloadTimeStamp,
    lat, lon, alt, HDOP, VDOP, PDOP, TDOP
  )
  VALUES
    (
      29, 34681, '28/01/2020 10:00',-24,
      155, 88, 649, 429,-768,-131
    );
  /* INSERT QUERY */
  INSERT INTO GPS(
    packID, seqPayload, payloadTimeStamp,
    lat, lon, alt, HDOP, VDOP, PDOP, TDOP
  )
  VALUES
    (
      30, 32483, '29/01/2020 10:00',-84,
      139, 169, 468, 761,-974, 642
    );
  /* INSERT QUERY */
  INSERT INTO GPS(
    packID, seqPayload, payloadTimeStamp,
    lat, lon, alt, HDOP, VDOP, PDOP, TDOP
  )
  VALUES
    (
      31, 63178, '30/01/2020 10:00', 39,
      50, 117,-898, 346, 56,-486
    );
  /* INSERT QUERY */
  INSERT INTO GPS(
    packID, seqPayload, payloadTimeStamp,
    lat, lon, alt, HDOP, VDOP, PDOP, TDOP
  )
  VALUES
    (
      32, 10241, '31/01/2020 10:00', 59,
      18, 145,-671, 215,-664,-160
    );
  /* INSERT QUERY */
  INSERT INTO GPS(
    packID, seqPayload, payloadTimeStamp,
    lat, lon, alt, HDOP, VDOP, PDOP, TDOP
  )
  VALUES
    (
      33, 34693, '01/02/2020 10:00',-41,
      54, 89,-607, 574,-257, 801
    );
  /* INSERT QUERY */
  INSERT INTO GPS(
    packID, seqPayload, payloadTimeStamp,
    lat, lon, alt, HDOP, VDOP, PDOP, TDOP
  )
  VALUES
    (
      34, 54413, '02/02/2020 10:00',-32,
      -117, 115,-252, 649,-616,-641
    );
  /* INSERT QUERY */
  INSERT INTO GPS(
    packID, seqPayload, payloadTimeStamp,
    lat, lon, alt, HDOP, VDOP, PDOP, TDOP
  )
  VALUES
    (
      35, 51887, '03/02/2020 10:00', 44,
      -13, 222,-643,-981,-92,-225
    );
  /* INSERT QUERY */
  INSERT INTO GPS(
    packID, seqPayload, payloadTimeStamp,
    lat, lon, alt, HDOP, VDOP, PDOP, TDOP
  )
  VALUES
    (
      36, 10353, '04/02/2020 10:00',-67,
      -127, 164,-506,-394, 45, 528
    );
  /* INSERT QUERY */
  INSERT INTO GPS(
    packID, seqPayload, payloadTimeStamp,
    lat, lon, alt, HDOP, VDOP, PDOP, TDOP
  )
  VALUES
    (
      37, 24022, '05/02/2020 10:00',-56,
      167, 245,-589, 756,-918, 496
    );
  /* INSERT QUERY */
  INSERT INTO GPS(
    packID, seqPayload, payloadTimeStamp,
    lat, lon, alt, HDOP, VDOP, PDOP, TDOP
  )
  VALUES
    (
      38, 59901, '06/02/2020 10:00', 43,
      -115, 96, 247, 958,-979,-351
    );
  /* INSERT QUERY */
  INSERT INTO GPS(
    packID, seqPayload, payloadTimeStamp,
    lat, lon, alt, HDOP, VDOP, PDOP, TDOP
  )
  VALUES
    (
      39, 32994, '07/02/2020 10:00',-88,
      -177, 216, 538, 301,-804, 274
    );
  /* INSERT QUERY */
  INSERT INTO GPS(
    packID, seqPayload, payloadTimeStamp,
    lat, lon, alt, HDOP, VDOP, PDOP, TDOP
  )
  VALUES
    (
      40, 40282, '08/02/2020 10:00', 35,
      83, 217, 104,-450,-897, 974
    );
  /* INSERT QUERY */
  INSERT INTO GPS(
    packID, seqPayload, payloadTimeStamp,
    lat, lon, alt, HDOP, VDOP, PDOP, TDOP
  )
  VALUES
    (
      41, 52697, '09/02/2020 10:00',-81,
      -176, 234, 143, 514, 461,-995
    );
  /* INSERT QUERY */
  INSERT INTO GPS(
    packID, seqPayload, payloadTimeStamp,
    lat, lon, alt, HDOP, VDOP, PDOP, TDOP
  )
  VALUES
    (
      42, 45178, '10/02/2020 10:00', 15,
      165, 138, 693, 560, 471,-698
    );
  /* INSERT QUERY */
  INSERT INTO GPS(
    packID, seqPayload, payloadTimeStamp,
    lat, lon, alt, HDOP, VDOP, PDOP, TDOP
  )
  VALUES
    (
      43, 44346, '11/02/2020 10:00',-89,
      -154, 152,-157,-952,-74, 279
    );
  /* INSERT QUERY */
  INSERT INTO GPS(
    packID, seqPayload, payloadTimeStamp,
    lat, lon, alt, HDOP, VDOP, PDOP, TDOP
  )
  VALUES
    (
      44, 9095, '12/02/2020 10:00',-32,
      69, 250,-699, 531,-618,-878
    );
  /* INSERT QUERY */
  INSERT INTO GPS(
    packID, seqPayload, payloadTimeStamp,
    lat, lon, alt, HDOP, VDOP, PDOP, TDOP
  )
  VALUES
    (
      45, 38963, '13/02/2020 10:00', 86,
      52, 203,-707, 710,-774,-314
    );
  /* INSERT QUERY */
  INSERT INTO GPS(
    packID, seqPayload, payloadTimeStamp,
    lat, lon, alt, HDOP, VDOP, PDOP, TDOP
  )
  VALUES
    (
      46, 16543, '14/02/2020 10:00', 63,
      8, 83, 742,-591, 295,-217
    );
  /* INSERT QUERY */
  INSERT INTO GPS(
    packID, seqPayload, payloadTimeStamp,
    lat, lon, alt, HDOP, VDOP, PDOP, TDOP
  )
  VALUES
    (
      47, 51355, '15/02/2020 10:00', 75,
      -6, 242, 626, 456,-183, 304
    );
  /* INSERT QUERY */
  INSERT INTO GPS(
    packID, seqPayload, payloadTimeStamp,
    lat, lon, alt, HDOP, VDOP, PDOP, TDOP
  )
  VALUES
    (
      48, 49725, '16/02/2020 10:00',-5,
      -114, 92,-471, 60, 869,-481
    );
  /* INSERT QUERY */
  INSERT INTO GPS(
    packID, seqPayload, payloadTimeStamp,
    lat, lon, alt, HDOP, VDOP, PDOP, TDOP
  )
  VALUES
    (
      49, 11022, '17/02/2020 10:00', 61,
      -157, 99,-428, 158,-641, 812
    );
  /* INSERT QUERY */
  INSERT INTO GPS(
    packID, seqPayload, payloadTimeStamp,
    lat, lon, alt, HDOP, VDOP, PDOP, TDOP
  )
  VALUES
    (
      50, 3139, '18/02/2020 10:00',-14,
      -14, 211, 576,-516, 484, 989
    );
  /* INSERT QUERY */
  INSERT INTO GPS(
    packID, seqPayload, payloadTimeStamp,
    lat, lon, alt, HDOP, VDOP, PDOP, TDOP
  )
  VALUES
    (
      51, 33113, '19/02/2020 10:00',-53,
      -69, 138,-110, 416, 864, 118
    );
  /* INSERT QUERY */
  INSERT INTO GPS(
    packID, seqPayload, payloadTimeStamp,
    lat, lon, alt, HDOP, VDOP, PDOP, TDOP
  )
  VALUES
    (
      52, 1934, '20/02/2020 10:00', 15, 40,
      169, 913, 731, 764,-737
    );
  /* INSERT QUERY */
  INSERT INTO GPS(
    packID, seqPayload, payloadTimeStamp,
    lat, lon, alt, HDOP, VDOP, PDOP, TDOP
  )
  VALUES
    (
      53, 65156, '21/02/2020 10:00',-15,
      -126, 229,-537,-540,-440,-436
    );
  /* INSERT QUERY */
  INSERT INTO GPS(
    packID, seqPayload, payloadTimeStamp,
    lat, lon, alt, HDOP, VDOP, PDOP, TDOP
  )
  VALUES
    (
      54, 53846, '22/02/2020 10:00',-67,
      75, 217, 141, 898,-566,-750
    );
  /* INSERT QUERY */
  INSERT INTO GPS(
    packID, seqPayload, payloadTimeStamp,
    lat, lon, alt, HDOP, VDOP, PDOP, TDOP
  )
  VALUES
    (
      55, 15365, '23/02/2020 10:00', 52,
      113, 89, 607,-428,-292,-419
    );
  /* INSERT QUERY */
  INSERT INTO GPS(
    packID, seqPayload, payloadTimeStamp,
    lat, lon, alt, HDOP, VDOP, PDOP, TDOP
  )
  VALUES
    (
      56, 46695, '24/02/2020 10:00',-24,
      17, 95,-918, 362, 701, 573
    );
  /* INSERT QUERY */
  INSERT INTO GPS(
    packID, seqPayload, payloadTimeStamp,
    lat, lon, alt, HDOP, VDOP, PDOP, TDOP
  )
  VALUES
    (
      57, 18512, '25/02/2020 10:00', 65,
      68, 156,-627,-546, 696,-144
    );
  /* INSERT QUERY */
  INSERT INTO GPS(
    packID, seqPayload, payloadTimeStamp,
    lat, lon, alt, HDOP, VDOP, PDOP, TDOP
  )
  VALUES
    (
      58, 61270, '26/02/2020 10:00',-13,
      160, 208, 942,-772,-704, 514
    );
  /* INSERT QUERY */
  INSERT INTO GPS(
    packID, seqPayload, payloadTimeStamp,
    lat, lon, alt, HDOP, VDOP, PDOP, TDOP
  )
  VALUES
    (
      59, 29589, '27/02/2020 10:00',-90,
      -105, 212, 882,-409, 734, 438
    );
  /* INSERT QUERY */
  INSERT INTO GPS(
    packID, seqPayload, payloadTimeStamp,
    lat, lon, alt, HDOP, VDOP, PDOP, TDOP
  )
  VALUES
    (
      60, 13057, '28/02/2020 10:00',-17,
      -21, 239, 8, 795,-306,-934
    );
  /* INSERT QUERY */
  INSERT INTO GPS(
    packID, seqPayload, payloadTimeStamp,
    lat, lon, alt, HDOP, VDOP, PDOP, TDOP
  )
  VALUES
    (
      61, 59565, '29/02/2020 10:00',-81,
      -15, 141, 136,-244,-164,-518
    );
  /* INSERT QUERY */
  INSERT INTO GPS(
    packID, seqPayload, payloadTimeStamp,
    lat, lon, alt, HDOP, VDOP, PDOP, TDOP
  )
  VALUES
    (
      62, 63473, '01/03/2020 10:00',-50,
      98, 161, 875,-442,-764,-661
    );
  /* INSERT QUERY */
  INSERT INTO GPS(
    packID, seqPayload, payloadTimeStamp,
    lat, lon, alt, HDOP, VDOP, PDOP, TDOP
  )
  VALUES
    (
      63, 13936, '02/03/2020 10:00',-88,
      46, 236, 718,-488,-430,-399
    );
  /* INSERT QUERY */
  INSERT INTO GPS(
    packID, seqPayload, payloadTimeStamp,
    lat, lon, alt, HDOP, VDOP, PDOP, TDOP
  )
  VALUES
    (
      64, 30838, '03/03/2020 10:00',-90,
      -60, 220,-7, 466,-251, 50
    );
  /* INSERT QUERY */
  INSERT INTO GPS(
    packID, seqPayload, payloadTimeStamp,
    lat, lon, alt, HDOP, VDOP, PDOP, TDOP
  )
  VALUES
    (
      65, 53036, '04/03/2020 10:00',-84,
      -139, 201,-628,-472,-780, 517
    );
  /* INSERT QUERY */
  INSERT INTO GPS(
    packID, seqPayload, payloadTimeStamp,
    lat, lon, alt, HDOP, VDOP, PDOP, TDOP
  )
  VALUES
    (
      66, 46238, '05/03/2020 10:00', 73,
      -164, 231, 66,-789,-21, 150
    );
  /* INSERT QUERY */
  INSERT INTO GPS(
    packID, seqPayload, payloadTimeStamp,
    lat, lon, alt, HDOP, VDOP, PDOP, TDOP
  )
  VALUES
    (
      67, 15766, '06/03/2020 10:00', 81,
      47, 238,-55, 332,-910,-817
    );
  /* INSERT QUERY */
  INSERT INTO GPS(
    packID, seqPayload, payloadTimeStamp,
    lat, lon, alt, HDOP, VDOP, PDOP, TDOP
  )
  VALUES
    (
      68, 29974, '07/03/2020 10:00',-38,
      -86, 178, 87,-598,-893,-154
    );
  /* INSERT QUERY */
  INSERT INTO GPS(
    packID, seqPayload, payloadTimeStamp,
    lat, lon, alt, HDOP, VDOP, PDOP, TDOP
  )
  VALUES
    (
      69, 63773, '08/03/2020 10:00', 38,
      115, 94,-985, 251, 818,-962
    );
  /* INSERT QUERY */
  INSERT INTO GPS(
    packID, seqPayload, payloadTimeStamp,
    lat, lon, alt, HDOP, VDOP, PDOP, TDOP
  )
  VALUES
    (
      70, 7350, '09/03/2020 10:00',-58,
      -104, 197, 962, 567, 31, 374
    );
  /* INSERT QUERY */
  INSERT INTO GPS(
    packID, seqPayload, payloadTimeStamp,
    lat, lon, alt, HDOP, VDOP, PDOP, TDOP
  )
  VALUES
    (
      71, 28937, '10/03/2020 10:00',-13,
      -110, 218, 448,-975, 948,-105
    );
  /* INSERT QUERY */
  INSERT INTO GPS(
    packID, seqPayload, payloadTimeStamp,
    lat, lon, alt, HDOP, VDOP, PDOP, TDOP
  )
  VALUES
    (
      72, 12147, '11/03/2020 10:00',-44,
      92, 187,-710,-617, 333,-874
    );
  /* INSERT QUERY */
  INSERT INTO GPS(
    packID, seqPayload, payloadTimeStamp,
    lat, lon, alt, HDOP, VDOP, PDOP, TDOP
  )
  VALUES
    (
      73, 60637, '12/03/2020 10:00', 9,-118,
      160, 551,-375, 827,-599
    );
  /* INSERT QUERY */
  INSERT INTO GPS(
    packID, seqPayload, payloadTimeStamp,
    lat, lon, alt, HDOP, VDOP, PDOP, TDOP
  )
  VALUES
    (
      74, 55114, '13/03/2020 10:00', 65,
      -179, 110,-443, 38, 1000, 981
    );
  /* INSERT QUERY */
  INSERT INTO GPS(
    packID, seqPayload, payloadTimeStamp,
    lat, lon, alt, HDOP, VDOP, PDOP, TDOP
  )
  VALUES
    (
      75, 1284, '14/03/2020 10:00', 2, 14,
      216,-223, 322,-139, 816
    );
  /* INSERT QUERY */
  INSERT INTO GPS(
    packID, seqPayload, payloadTimeStamp,
    lat, lon, alt, HDOP, VDOP, PDOP, TDOP
  )
  VALUES
    (
      76, 14771, '15/03/2020 10:00',-52,
      -4, 142, 320, 201,-690,-832
    );
  /* INSERT QUERY */
  INSERT INTO GPS(
    packID, seqPayload, payloadTimeStamp,
    lat, lon, alt, HDOP, VDOP, PDOP, TDOP
  )
  VALUES
    (
      77, 48335, '16/03/2020 10:00', 83,
      11, 170,-243,-443, 684,-444
    );
  /* INSERT QUERY */
  INSERT INTO GPS(
    packID, seqPayload, payloadTimeStamp,
    lat, lon, alt, HDOP, VDOP, PDOP, TDOP
  )
  VALUES
    (
      78, 35803, '17/03/2020 10:00',-76,
      -28, 148, 955, 155, 7,-990
    );
  /* INSERT QUERY */
  INSERT INTO GPS(
    packID, seqPayload, payloadTimeStamp,
    lat, lon, alt, HDOP, VDOP, PDOP, TDOP
  )
  VALUES
    (
      79, 57081, '18/03/2020 10:00',-17,
      -84, 120, 601, 505, 939,-457
    );
  /* INSERT QUERY */
  INSERT INTO GPS(
    packID, seqPayload, payloadTimeStamp,
    lat, lon, alt, HDOP, VDOP, PDOP, TDOP
  )
  VALUES
    (
      80, 31054, '19/03/2020 10:00',-69,
      -37, 222, 992, 549, 861, 81
    );
  /* INSERT QUERY */
  INSERT INTO GPS(
    packID, seqPayload, payloadTimeStamp,
    lat, lon, alt, HDOP, VDOP, PDOP, TDOP
  )
  VALUES
    (
      81, 58925, '20/03/2020 10:00', 61,
      102, 83, 860, 40, 279, 786
    );
  /* INSERT QUERY */
  INSERT INTO GPS(
    packID, seqPayload, payloadTimeStamp,
    lat, lon, alt, HDOP, VDOP, PDOP, TDOP
  )
  VALUES
    (
      82, 58566, '21/03/2020 10:00', 46,
      -95, 193,-967,-372, 833, 14
    );
  /* INSERT QUERY */
  INSERT INTO GPS(
    packID, seqPayload, payloadTimeStamp,
    lat, lon, alt, HDOP, VDOP, PDOP, TDOP
  )
  VALUES
    (
      83, 18672, '22/03/2020 10:00', 58,
      173, 189, 524, 888, 662, 376
    );
  /* INSERT QUERY */
  INSERT INTO GPS(
    packID, seqPayload, payloadTimeStamp,
    lat, lon, alt, HDOP, VDOP, PDOP, TDOP
  )
  VALUES
    (
      84, 27303, '23/03/2020 10:00',-71,
      -98, 190, 13, 723, 749, 509
    );
  /* INSERT QUERY */
  INSERT INTO GPS(
    packID, seqPayload, payloadTimeStamp,
    lat, lon, alt, HDOP, VDOP, PDOP, TDOP
  )
  VALUES
    (
      85, 47698, '24/03/2020 10:00',-39,
      -117, 191, 584, 182,-276,-715
    );
  /* INSERT QUERY */
  INSERT INTO GPS(
    packID, seqPayload, payloadTimeStamp,
    lat, lon, alt, HDOP, VDOP, PDOP, TDOP
  )
  VALUES
    (
      86, 49547, '25/03/2020 10:00',-44,
      -163, 245, 105, 409, 64, 353
    );
  /* INSERT QUERY */
  INSERT INTO GPS(
    packID, seqPayload, payloadTimeStamp,
    lat, lon, alt, HDOP, VDOP, PDOP, TDOP
  )
  VALUES
    (
      87, 27528, '26/03/2020 10:00', 43,
      89, 125,-208,-98,-469, 29
    );
  /* INSERT QUERY */
  INSERT INTO GPS(
    packID, seqPayload, payloadTimeStamp,
    lat, lon, alt, HDOP, VDOP, PDOP, TDOP
  )
  VALUES
    (
      88, 21412, '27/03/2020 10:00', 30,
      -151, 233,-88, 800,-73,-116
    );
  /* INSERT QUERY */
  INSERT INTO GPS(
    packID, seqPayload, payloadTimeStamp,
    lat, lon, alt, HDOP, VDOP, PDOP, TDOP
  )
  VALUES
    (
      89, 53565, '28/03/2020 10:00',-42,
      144, 123,-133, 331,-832,-450
    );
  /* INSERT QUERY */
  INSERT INTO GPS(
    packID, seqPayload, payloadTimeStamp,
    lat, lon, alt, HDOP, VDOP, PDOP, TDOP
  )
  VALUES
    (
      90, 40096, '29/03/2020 10:00',-86,
      -140, 123, 914,-506, 305, 941
    );
  /* INSERT QUERY */
  INSERT INTO GPS(
    packID, seqPayload, payloadTimeStamp,
    lat, lon, alt, HDOP, VDOP, PDOP, TDOP
  )
  VALUES
    (
      91, 10450, '30/03/2020 10:00',-81,
      -9, 93,-645, 724, 277, 708
    );
  /* INSERT QUERY */
  INSERT INTO GPS(
    packID, seqPayload, payloadTimeStamp,
    lat, lon, alt, HDOP, VDOP, PDOP, TDOP
  )
  VALUES
    (
      92, 27611, '31/03/2020 10:00',-51,
      134, 174, 807,-992, 952, 103
    );
  /* INSERT QUERY */
  INSERT INTO GPS(
    packID, seqPayload, payloadTimeStamp,
    lat, lon, alt, HDOP, VDOP, PDOP, TDOP
  )
  VALUES
    (
      93, 11944, '01/04/2020 10:00',-57,
      -43, 221,-334,-451, 583, 736
    );
  /* INSERT QUERY */
  INSERT INTO GPS(
    packID, seqPayload, payloadTimeStamp,
    lat, lon, alt, HDOP, VDOP, PDOP, TDOP
  )
  VALUES
    (
      94, 1130, '02/04/2020 10:00', 38, 6,
      203,-316, 271, 863, 848
    );
  /* INSERT QUERY */
  INSERT INTO GPS(
    packID, seqPayload, payloadTimeStamp,
    lat, lon, alt, HDOP, VDOP, PDOP, TDOP
  )
  VALUES
    (
      95, 24095, '03/04/2020 10:00', 84,
      122, 208, 348, 646, 982,-527
    );
  /* INSERT QUERY */
  INSERT INTO GPS(
    packID, seqPayload, payloadTimeStamp,
    lat, lon, alt, HDOP, VDOP, PDOP, TDOP
  )
  VALUES
    (
      96, 45066, '04/04/2020 10:00', 5, 105,
      127,-79,-241, 116,-910
    );
  /* INSERT QUERY */
  INSERT INTO GPS(
    packID, seqPayload, payloadTimeStamp,
    lat, lon, alt, HDOP, VDOP, PDOP, TDOP
  )
  VALUES
    (
      97, 59152, '05/04/2020 10:00', 11,
      52, 183, 765, 881, 429,-23
    );
  /* INSERT QUERY */
  INSERT INTO GPS(
    packID, seqPayload, payloadTimeStamp,
    lat, lon, alt, HDOP, VDOP, PDOP, TDOP
  )
  VALUES
    (
      98, 19657, '06/04/2020 10:00',-90,
      -172, 250, 110,-268, 111, 821
    );
  /* INSERT QUERY */
  INSERT INTO GPS(
    packID, seqPayload, payloadTimeStamp,
    lat, lon, alt, HDOP, VDOP, PDOP, TDOP
  )
  VALUES
    (
      99, 58675, '07/04/2020 10:00',-55,
      37, 187, 256, 700,-982, 7
    );
  /* INSERT QUERY */
  INSERT INTO GPS(
    packID, seqPayload, payloadTimeStamp,
    lat, lon, alt, HDOP, VDOP, PDOP, TDOP
  )
  VALUES
    (
      100, 5772, '08/04/2020 10:00',-39,
      -129, 223,-213,-842,-304, 496
    );
