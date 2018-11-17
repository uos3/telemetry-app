struct IMU {
	char dataset_id[3];
	uint32_t timestamp;
	int16_t mag_x[5];
	int16_t mag_y[5];
	int16_t mag_z[5];
	int16_t gyro_x[5];
	int16_t gyro_y[5];
	int16_t gyro_z[5];
	int16_t accel_x[5];
	int16_t accel_y[5];
	int16_t accel_z[5];
};
