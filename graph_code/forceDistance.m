% Distance tests
force0in = readtable('/Users/raoshilpa/Desktop/capstone-1/3.13.24_ForceTests/force0curr_control.csv');
force2in = readtable('/Users/raoshilpa/Desktop/capstone-1/3.13.24_ForceTests/force2in.csv', 'NumHeaderLines', 9);
force4in = readtable('/Users/raoshilpa/Desktop/capstone-1/3.13.24_ForceTests/force4in.csv');
force8in = readtable('/Users/raoshilpa/Desktop/capstone-1/3.13.24_ForceTests/force8in.csv');
force10in = readtable('/Users/raoshilpa/Desktop/capstone-1/3.13.24_ForceTests/force10in.csv');

% 2 in
time2 = force2in{:,1};
sensor1test2 = force2in{:,2};
sensor1test2norm = (sensor1test2 - min(sensor1test2)) / (max(sensor1test2) - min(sensor1test2));
sensor2test2 = force2in{:,3};
sensor2test2norm = (sensor2test2 - min(sensor2test2)) / (max(sensor2test2) - min(sensor2test2));
sensor3test2 = force2in{:,4};
sensor3test2norm = (sensor3test2 - min(sensor3test2)) / (max(sensor3test2) - min(sensor3test2));
sensor4test2 = force2in{:,5};
sensor4test2norm = (sensor4test2 - min(sensor4test2)) / (max(sensor4test2) - min(sensor4test2));

figure;
hold on;
plot(time2,sensor1test2, '-o', 'Color', 'red');
plot(time2,sensor2test2, '-o', 'Color', 'blue');
plot(time2,sensor3test2, '-o', 'Color', 'green');
plot(time2,sensor4test2, '-o', 'Color', 'black');
% ylim([2000 2500])
hold off;

% 4 in
time4 = force4in{:,1};
sensor1test4 = force4in{:,2};
sensor1test4norm = (sensor1test4 - min(sensor1test4)) / (max(sensor1test4) - min(sensor1test4));
sensor2test4 = force4in{:,3};
sensor2test4norm = (sensor2test4 - min(sensor2test4)) / (max(sensor2test4) - min(sensor2test4));
sensor3test4 = force4in{:,4};
sensor3test4norm = (sensor3test4 - min(sensor3test4)) / (max(sensor3test4) - min(sensor3test4));
sensor4test4 = force4in{:,5};
sensor4test4norm = (sensor4test4 - min(sensor4test4)) / (max(sensor4test4) - min(sensor4test4));

% figure;
% subplot(4,1,1);
% hold on;
% plot(time2, sensor1test2norm, 'Color', 'red');
% plot(time2, sensor2test2norm, 'Color', 'blue');
% plot(time2, sensor3test2norm, 'Color', 'green');
% plot(time2, sensor4test2norm, 'Color', 'black');
% legend('Sensor 1','Sensor 2','Sensor 3','Sensor 4');
% hold off;
% title('2 inches: Normalized Force Readings vs. Time');
% xlabel('Time');
% ylabel('Force Values');
% hold off;
% 
% subplot(4,1,2);
% hold on;
% plot(time4, sensor1test4norm, 'Color', 'red');
% plot(time4, sensor2test4norm, 'Color', 'blue');
% plot(time4, sensor3test4norm, 'Color', 'green');
% plot(time4, sensor4test4norm, 'Color', 'black');
% legend('Sensor 1','Sensor 2','Sensor 3','Sensor 4');
% hold off;
% title('4 inches: Normalized Force Readings vs. Time');
% xlabel('Time');
% ylabel('Force Values');
% hold off;

% GET TABLE VALUES
arr0 = [];
arr2 = [];
arr4 = [];
arr8 = [];
arr10 = [];

sensor1test0 = force0in{:,2};
sensor2test0 = force0in{:,3};
sensor3test0 = force0in{:,4};
sensor4test0 = force0in{:,5};
arr0(1) = max(sensor1test0) - min(sensor1test0);
arr0(2) = max(sensor2test0) - min(sensor2test0);
arr0(3) = max(sensor3test0) - min(sensor3test0);
arr0(4) = max(sensor4test0) - min(sensor4test0);

sensor1test2 = force2in{:,2};
sensor1test2norm = (sensor1test2 - min(sensor1test2)) / (max(sensor1test2) - min(sensor1test2));
sensor2test2 = force2in{:,3};
sensor2test2norm = (sensor2test2 - min(sensor2test2)) / (max(sensor2test2) - min(sensor2test2));
sensor3test2 = force2in{:,4};
sensor3test2norm = (sensor3test2 - min(sensor3test2)) / (max(sensor3test2) - min(sensor3test2));
sensor4test2 = force2in{:,5};
sensor4test2norm = (sensor4test2 - min(sensor4test2)) / (max(sensor4test2) - min(sensor4test2));
arr2(1) = max(sensor1test2) - min(sensor1test2);
arr2(2) = max(sensor2test2) - min(sensor2test2);
arr2(3) = max(sensor3test2) - min(sensor3test2);
arr2(4) = max(sensor4test2) - min(sensor4test2);

sensor1test4 = force4in{:,2};
sensor2test4 = force4in{:,3};
sensor3test4 = force4in{:,4};
sensor4test4 = force4in{:,5};
arr4(1) = max(sensor1test4) - min(sensor1test4);
arr4(2) = max(sensor2test4) - min(sensor2test4);
arr4(3) = max(sensor3test4) - min(sensor3test4);
arr4(4) = max(sensor4test4) - min(sensor4test4);

sensor1test8 = force8in{:,2};
sensor2test8 = force8in{:,3};
sensor3test8 = force8in{:,4};
sensor4test8 = force8in{:,5};
arr8(1) = max(sensor1test8) - min(sensor1test8);
arr8(2) = max(sensor2test8) - min(sensor2test8);
arr8(3) = max(sensor3test8) - min(sensor3test8);
arr8(4) = max(sensor4test8) - min(sensor4test8);

sensor1test10 = force10in{:,2};
sensor2test10 = force10in{:,3};
sensor3test10 = force10in{:,4};
sensor4test10 = force10in{:,5};
arr10(1) = max(sensor1test10) - min(sensor1test10);
arr10(2) = max(sensor2test10) - min(sensor2test10);
arr10(3) = max(sensor3test10) - min(sensor3test10);
arr10(4) = max(sensor4test10) - min(sensor4test10);
