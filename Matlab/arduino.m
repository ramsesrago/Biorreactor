clear all; close all; clc;

Vt  = zeros(1,200);
Xi  = zeros(1,200);
Sc  = zeros(1,200);
Soi = zeros(1,200);

t = linspace(0, 20, 200);

% Init serial port
delete(instrfind({'Port'},{'COM26'}));
sp = serial('COM26');
sp.BaudRate = 9600;
set(sp, 'Terminator', 'CR'); % set communication string to end on ASCII 13
warning('off', 'MATLAB:serial:fscanf:unsuccessfulRead');
flushinput(sp);
set(sp, 'InputBufferSize', 2048) ; 
% Open serial port
fopen(sp);

% Vt
m = fgets(sp);
Vt = strsplit(m, ',');
Vt = char(Vt);
Vt = str2num(Vt);
Vt = Vt';

figure;
title('V(t)');
xlabel('t (s)');
ylabel('Sample value');
grid on; hold on;
Vt_plot = plot(t, Vt);

% Xi
m = fgets(sp);
Xi = strsplit(m, ',');
Xi = char(Xi);
Xi = str2num(Xi);
Xi = Xi';

figure;
title('Xi(t)');
xlabel('t (s)');
ylabel('Sample value');
grid on; hold on;
Xi_plot = plot(t, Xi);

% Sc
m = fgets(sp);
Sc = strsplit(m, ',');
Sc = char(Sc);
Sc = str2num(Sc);
Sc = Sc';

figure;
title('Sc(t)');
xlabel('t (s)');
ylabel('Sample value');
grid on; hold on;
Sc_plot = plot(t, Sc);

% Sc
m = fgets(sp);
Soi = strsplit(m, ',');
Soi = char(Soi);
Soi = str2num(Soi);
Soi = Soi';

figure;
title('Sot(t)');
xlabel('t (s)');
ylabel('Sample value');
grid on; hold on;
Soi_plot = plot(t, Soi);


fclose(sp);
delete(sp);
