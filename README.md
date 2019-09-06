## Algorithm to estimate roll and pitch angles from a dataset of raw readings.

This project can be divided in three main modules, such as: 

- <b>application;</b>
- <b>logs (I/O);</b>
- <b>tests.</b>

The application is formed by the files main.cpp, accelerometersample.cpp e accelerometersample.h. While the first file is responsible for reading and writing logs, the another ones are responsible for parse samples and estimate Roll and Picth. The estimation is based on the equations 37 and 38 ([application-note](https://www.nxp.com/docs/en/application-note/AN3461.pdf)) to avoid regions of instability. 

In the I/O module, there are two log files in the logs directory, input log (attitude_exam.log) and output log (roll_pitch.log). The first log contains the accelerometer measures, wich are employed to estimate Roll and Pitch angles. These estimations can be saved (in <b>degrees</b>) in the output log, following the pattern:

<p align="center"><b>
  (time_stamp_ms; roll; pitch)
</b></p>

In the Test moldule, unit tests are used to evaluate if the estimations are correct and also to verify if the samples respect the model constraint (Gpx^2 + Gpy^2 + Gpz^2 = 1g^2). This constraint is employed to avoid noises (errors) above a determined value. [The Cacth framework](https://github.com/catchorg/Catch2) is used for write the tests. This framework is composed by a single header file and does not need instalation.  

## To run

The application and tests execution is simplified by Makefile file. For execute them is necessary to be in the same directory of Makefile and have the `make command` available.

### Commands to run application
- `make all`
- `./app`
- `make clean`

### Commands to run tests
- `make test`
- `./test`
- `make clean`
