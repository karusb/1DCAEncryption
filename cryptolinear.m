

monobitfile = 'SYMMETRIC_KEYENC/data/loriupsum/nonlinearitydata.txt';
pokerfile = 'SYMMETRIC_KEYENC/data/loriupsum/pokerfile.txt';
monobitfile1 = 'SYMMETRIC_KEYENC/data/loriupsum20/nonlinearitydata.txt';
pokerfile1 = 'SYMMETRIC_KEYENC/data/loriupsum20/pokerfile.txt';
monobitfile2 = 'SYMMETRIC_KEYENC/data/firstsample/nonlinearitydata.txt';
pokerfile2 = 'SYMMETRIC_KEYENC/data/firstsample/pokerfile.txt';
% monobitfile3 = 'SYMMETRIC_KEYENC/data/loriupsum201/nonlinearitydata8.txt';
% pokerfile3 = 'SYMMETRIC_KEYENC/data/loriupsum201/pokerfile.txt';
monobitfile4 = 'SYMMETRIC_KEYENC/data/loriupsum202/nonlinearitydata.txt';
pokerfile4 = 'SYMMETRIC_KEYENC/data/loriupsum202/pokerfile.txt';
monobitfile5 = 'SYMMETRIC_KEYENC/data/loriupsum203/nonlinearitydata.txt';
pokerfile5 = 'SYMMETRIC_KEYENC/data/loriupsum203/pokerfile.txt';
delimiter = '\n';
P1 = importdata(pokerfile,delimiter);
P2 = importdata(pokerfile1,delimiter);
P3 = importdata(pokerfile2,delimiter);
%P4 = importdata(pokerfile3,delimiter);
P5 = importdata(pokerfile4,delimiter);
P6 = importdata(pokerfile5,delimiter);
S1 = importdata(monobitfile,delimiter);
S2 = importdata(monobitfile1,delimiter);
S3 = importdata(monobitfile2,delimiter);
%S4 = importdata(monobitfile3,delimiter);
S5 = importdata(monobitfile4,delimiter);
S6 = importdata(monobitfile5,delimiter);

 figure
 plot(4:4:size(S1)*4,S1)
 title('Frequency of 1s every 4 bits throughout the key sequence for 5000 Bits Long Message&Key, Initial key = "nottingham" Evolved for 4000 gens')
 xlabel('nth Bit in 4 bit sets')
 ylabel('Percentage of "1" bits')  
 figure
 plot(4:4:size(S2)*4,S2)
 title('Frequency of 1s every 4 bits throughout the key sequence for 20000 Bits Long Message&Key, Initial key = "nottingham" Evolved for 19000 gens')
 xlabel('nth Bit in 4 bit sets')
 ylabel('Percentage of "1" bits')  
 figure
 plot(4:4:size(S3)*4,S3)
 title('Frequency of 1s every 4 bits throughout the key sequence for 344 Bits Long Message&Key, Initial key = "nottingham" Evolved for 3354 gens')
 xlabel('nth Bit in 4 bit sets')
 ylabel('Percentage of "1" bits')  
 
 figure
 plot(4:4:size(S5)*4,S5)
title('Frequency of 1s every 4 bits throughout the key sequence for 20000 Bits Long Message&Key, Initial key = "mysecurepassword12" Evolved for 19000 gens')
 xlabel('nth Bit in 4 bit sets')
 ylabel('Percentage of "1" bits')  
 
  figure
 plot(4:4:size(S6)*4,S6)
title('Frequency of 1s every 4 bits throughout the key sequence for 20000 Bits Long Message&Key, Initial key = "mysecurepassword12" Evolved for 19002 gens')
 xlabel('nth Bit in 4 bit sets')
 ylabel('Percentage of "1" bits')  
 
figure
plot(0:1:15,P1)
title('%Poker test of initial key = "nottingham" Evolved for 4000 gens 5000bits long')
xlabel('Bit Integer Value')
ylabel('Occurence in Key Sequence')
figure
plot(0:1:15,P2)
title('%Poker test of initial key = "nottingham" Evolved for 19000 gens 20000bits long ')
xlabel('Bit Integer Value')
ylabel('Occurence in Key Sequence')
figure
plot(0:1:15,P3)
title('%Poker test of initial key = "nottingham" Evolved for 3354 gens 344bits long ')
xlabel('Bit Integer Value')
ylabel('Occurence in Key Sequence')
figure
plot(0:1:15,P5)
title('%Poker test of initial key = "mysecurepassword12" Evolved for 19000 gens 20000bits long ')
xlabel('Bit Integer Value')
ylabel('Occurence in Key Sequence')
figure
plot(0:1:15,P6)
title('%Poker test of initial key = "mysecurepassword12" Evolved for 19002 gens 20000bits long ')
xlabel('Bit Integer Value')
ylabel('Occurence in Key Sequence')
%Needs to be less than 48.27 over 2500bytes
M1 = mean(S1)

M2 = mean(S2)

M3 = mean(S3)

M5 = mean(S5)

%M4 = mean(S4)

M6 = mean(S6)

MP1 = mean(P1)
MP2 = mean(P2)
MP3 = mean(P3)
MP5 = mean(P5)
MP6 = mean(P6)
%MP4 = mean(P4)
for i = 1:16
    P11(i) = (P1(i) - MP1)^2;
    P21(i) = (P2(i) - MP2)^2;
    P31(i) = (P3(i) - MP3)^2;
    P51(i) = (P5(i) - MP5)^2;
    P61(i) = (P6(i) - MP6)^2;
end;
for i = 1:16
    Pnew(i) = (P1(i) * P1(i));
    Pnew2(i) = (P2(i) * P2(i));
    Pnew3(i) = (P3(i) * P3(i));
    Pnew4(i) = (P5(i) * P5(i));
    Pnew5(i) = (P6(i) * P6(i));
end;

P1res = ((16.0/1250)*sum(Pnew)) - 1250
P2res = ((16.0/5000)*sum(Pnew2)) - 5000
P3res = ((16.0/86)*sum(Pnew3)) - 86
P5res = ((16.0/5000)*sum(Pnew4)) - 5000
P6res = ((16.0/5000)*sum(Pnew5)) - 5000
%standard deviation should be less then 2.93
MP11 = sqrt(sum(P11)/16)
MP11U = MP1 + MP11;
MP11D = MP1 - MP11;
MP21 = sqrt(sum(P21)/16)
MP31 = sqrt(sum(P31)/16) %within range for 1024 byte ( <23.5)
MP41 = sqrt(sum(P51)/16) %within range for 2048 byte ( <46  )
MP51 = sqrt(sum(P61)/16)
    