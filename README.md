# TimeElapsed
The C++11 header file to provide a simple TIME_ELAPSED macros to measure the elapsed time of a code block.

The code has been tested with VisualStudio 2013 on Windows7 and g++ 4.8.2 on CentOS7.


## 1. Header file

    TimeElapsed.hpp


## 2. Macro API

### 2.1. TIME_ELAPSED(target_code)

Measure the elapsed time of `target_code` and printout the time after executing it.
`target_code` can be a whole code block as well as a simple expression.

The output line is formated as:

```
ElapsedTime: <file_name> at L.<line_number>     cnt:<iteration_count>    <elapsed_time> msec
```

For example,

```
ElapsedTime: main.c at L.25                     cnt:1           25.400 msec
```


### 2.2. TIME_ELAPSED_EXP(target_code)

This macro is the same as **TIME_ELAPSED()** except that the header is the stringified `target_code`.
For example,

```
ElapsedTime: f += very_slow_func(123);          cnt:1           25.400 msec
```


### 2.3. TIME_ELAPSED_MARKER(marker,body)

This macro is the same as **TIME_ELAPSED()** except that the header is given by the user.
For example,

```
ElapsedTime: Arigorithm 1  param x=4,y=7        cnt:1           11.200 msec
```


### 2.4. Loop versions

The following macros will measure the elapsed time after running a loop of `target_code` by `n` times.

  - `TIME_ELAPSED_N(n,body)`
  - `TIME_ELAPSED_EXP_N(n,body)`
  - `TIME_ELAPSED_MARKER_N(n,marker,body)`
 
The elapsed time is calculated for the whole loop run.


### 2.5. NO_TIME_ELAPSED_MEASUREMENT

If defined, TIME_ELAPSED* macros will not measure the time nor generate any output.



## 3. Tutorial

Basically you can insert the macro around the concerned code block.  For example, the following code block:

```cpp
  cv::SiftFeatureDetector detector(0.05,10.0);
  cv::Scalar color(100,50,255);
```

can be measured as the below:

```cpp
  TIME_ELAPSED(
  
  cv::SiftFeatureDetector detector(0.05,10.0);
  cv::Scalar color(100,50,255);
  
  );
```

After the completion of cv::Scalar, **TIME_ELAPSED** will print the elapsed time.

See main.cpp for the more examples.


## 4. Porability

The header file uses C++11 standard only: macro, lambda, chrono, string, and ostream.
Thus the code should be portable.


--------
THIS IS THE END OF THE FILE.
