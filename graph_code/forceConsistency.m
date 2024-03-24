% Force consistency tests
forceTest1 = readtable('/Users/raoshilpa/Desktop/capstone-1/3.6.24_ForceTests/forceTest1.csv');
forceTest2 = readtable('/Users/raoshilpa/Desktop/capstone-1/3.6.24_ForceTests/forceTest2.csv', 'NumHeaderLines', 1);

% Force test 1
pwm1 = forceTest1{:,2}; % recorded with pyserial, so it has real timestamps
len = length(pwm1);
indices1 = 1:len;

% NORMALIZE FORCE READINGS
sensor1test1 = forceTest1{:,2};
sensor1test1norm = (sensor1test1 - min(sensor1test1)) / (max(sensor1test1) - min(sensor1test1));
sensor2test1 = forceTest1{:,3};
sensor2test1norm = (sensor2test1 - min(sensor2test1)) / (max(sensor2test1) - min(sensor2test1));
sensor3test1 = forceTest1{:,4};
sensor3test1norm = (sensor3test1 - min(sensor3test1)) / (max(sensor3test1) - min(sensor3test1));
sensor4test1 = forceTest1{:,5};
sensor4test1norm = (sensor4test1 - min(sensor4test1)) / (max(sensor4test1) - min(sensor4test1));

% GRAPH FORCE TEST 1 DATA
figure;
subplot(2, 1, 1);
hold on;
plot(indices1, sensor1test1norm, 'Color', 'red');
plot(indices1, sensor2test1norm, 'Color', 'blue');
plot(indices1, sensor3test1norm, 'Color', 'green');
plot(indices1, sensor4test1norm, 'Color', 'black');
legend('Sensor 1','Sensor 2','Sensor 3','Sensor 4');
hold off;
title('Force Readings vs. Index');
xlabel('Indices');
ylabel('Force Values');

subplot(2, 1, 2);
plot(indices1, pwm1);
title('PWM vs. Index');
xlabel('Index');
ylabel('PWM in multiples of 4');
% hold off;

% pwm1 = forceTest1{:,1}; % manually copied over from arduino serial
% sensor1test1 = forceTest1{:,2};
% sensor1test1norm = (sensor1test1 - min(sensor1test1)) / (max(sensor1test1) - min(sensor1test1));
% plot(pwm1, sensor1test1norm);
% sensor2test1 = forceTest1(:,3);
% sensor3test1 = forceTest1(:,4);
% sensor4test1 = forceTest1(:,5);



% Force test 2
time2 = forceTest2{:,1};
pwm2 = forceTest2{:,2}; % recorded with pyserial, so it has real timestamps

% NORMALIZE FORCE READINGS
sensor1test2 = forceTest2{:,3};
sensor1test2norm = (sensor1test2 - min(sensor1test2)) / (max(sensor1test2) - min(sensor1test2));
sensor2test2 = forceTest2{:,4};
sensor2test2norm = (sensor2test2 - min(sensor2test2)) / (max(sensor2test2) - min(sensor2test2));
sensor3test2 = forceTest2{:,5};
sensor3test2norm = (sensor3test2 - min(sensor3test2)) / (max(sensor3test2) - min(sensor3test2));
sensor4test2 = forceTest2{:,6};
sensor4test2norm = (sensor4test2 - min(sensor4test2)) / (max(sensor4test2) - min(sensor4test2));

% data_type = class(sensor1test2norm); % CHECK DATA TYPE IF NEED BE
% disp(data_type);

% GRAPH FORCE TEST 2 DATA
figure;
subplot(2, 1, 1);
hold on;
plot(time2, sensor1test2norm,'-o', 'Color', 'red');
plot(time2, sensor2test2norm, 'Color', 'blue');
plot(time2, sensor3test2norm, 'Color', 'green');
plot(time2, sensor4test2norm, 'Color', 'black');
legend('Sensor 1','Sensor 2','Sensor 3','Sensor 4');
hold off;
title('Normalized Force Readings vs. Time');
xlabel('Time');
ylabel('Force Values');

subplot(2, 1, 2);
plot(time2, pwm2,'-o');
title('PWM vs. Time');
xlabel('Time');
ylabel('PWM in multiples of 4');
% hold off;

