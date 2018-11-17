* why is it called time in gps, but timestamp elsewhere?
* which values are signed/unsigned?
* why is `battery_voltage` 8 bits in 'status', but 10 bits in 'health'?
* which values should be represented as floating point?
	* "real" seems like a bit of a misleading word to use in the spreadsheet,
	if they don't mean 'real-valued numbers' in the mathematical sense.
	* if there are floating point values that aren't 32 or 64 bits, how should
	these be parsed?
* how big is the image data?
* why is `self_test` in 'config' a 1 bit integer, instead of a bool? what does
this signify?
* why is the `secret key` in between the hash & crc in 'config', where they're
together in other packets? (I'm assuming it's a 48 bit MAC address)
* in 'config', `tx_datarate` is said to be an enumerated type. however, the
comments section seems to imply it's values fall in a decimal range. I'm not
sure what this means.
* apparently all of the fields marked as 'character strings' apart from
the spacecraft_id are not in fact character strings. why?

