## Algorithm to estimate roll and pitch angles from a dataset of raw readings.

Basically, this project is compose by three main modules, such as: 

- <b>application;</b>
- <b>logs;</b>
- <b>tests.</b>

The application is formed by the files main.cpp, accelerometersample.cpp e accelerometersample.h. Briefly, while the first file is responsible for reading and writing logs, the another ones are responsibles for samples verification and Roll and Picth estimate.

There are two logs, input log (attitude_exam.log) and output log (roll_pitch.log). The first one is constitute for the accelerometer measures and the second for the Roll and Pitch estimation, represented in degrees. The input log samples are read and employed for calculate the rotations, that is respectively written and saved in output log, in the follow format: 

<p align="center"><b>
  (time_stamp_ms; roll; pitch)
</b></p>

Finally, some the tests verify if the estimates are correct by testing some specifical samples. Furthermore, based on article (application-note), anothers the tests verify if the samples respect the model constraints. For easier portability, the tests use Cacth2 framework, which is only composed by a header file and do not need instalation.  

## To run

The application and tests execution is controlled by Makefile file. For execute them is necessary been in the same directory of Makefile. In addition, is necessary have the `make` installed.

### Commands to run application
- `make all`
- `./app`
- `make clean`

### Commands to run tests
- `make test`
- `./test`
- `make clean`
