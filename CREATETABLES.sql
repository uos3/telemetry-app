/* CREATE TABLE PACKETS */
CREATE TABLE IF NOT EXISTS PACKETS(
  packID INT(11) NOT NULL AUTO_INCREMENT PRIMARY KEY, 
  packBIN VARCHAR(100), 
  packCHK VARCHAR(100), 
  packHASH VARCHAR(100), 
  seqStat INT(11), 
  seqSecond INT(11), 
  secondType INT(11),
  downlinkTime VARCHAR(100)
  );
/* CREATE TABLE STATUS */
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
/* CREATE TABLE GPS*/
CREATE TABLE IF NOT EXISTS GPS(
  packID INT(11), 
  seqSecond DECIMAL(10, 2), 
  timeStamp VARCHAR(100), 
  lat DECIMAL(10, 2), 
  lon DECIMAL(10, 2), 
  alt DECIMAL(10, 2), 
  HDOP DECIMAL(10, 2), 
  VDOP DECIMAL(10, 2), 
  PDOP DECIMAL(10, 2), 
  TDOP DECIMAL(10, 2)
);
