
    BazCrypt 4 Neighbourhood Cellular Automata XOR Encryption
    Copyright (C) 2017  Baris Tanyeri

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
------------------------------BAZCRYPT 1DCA Encryption --------------------------
This free program allows you to encrypt any text based data with your given
 generation and password. You have to remember your generation and password to 
restore your data to its original state. If you would like to keep your original 
file and generate a new encrypted file, use "-n" parameter. Example batch files 
are given as RUN-BazcryptNEW.bat and RUN-Bazcrypt.bat. You need to edit the .bat
files to your purpose.

Example:Bazcrypt.exe -f myfile.txt -g 1502 -p yourpassword

To decrypt a file, use the same commands that were are previously used.
---------------------------------------------------------------------------------
----------------------------------COMMANDS---------------------------------------
----------------- MUST COMMANDS -------------------------------------------------
-f	File input (use only text based) followed with file name
			or
-m	Message input followed with the message (no spaces allowed)
			and
-g	Generation (Receiver must know this)
-p	Password   (Receiver must know this too!)

----------------- OPTIONAL COMMANDS ---------------------------------------------
-a	Key Expansion Algorithm Rules
		0	Cyclic Boundary 57630
		1	Zero Boundary 57630
		2	Cyclic Boundary 39318
		Default : 0
-b	Enables encrypted file output in bits, default is disabled.

-De	Enables encryption debug mode which shows every operation performed on 
	8 bit basis.

-R	Readback, enable this if you would like to see integrity of your data,
	this shows input plain text and password in clear.

-Ko	Outputs the generated secret key. This can be used to retrieve encrypted
	data encrypted with the same key by XORing key and the encrypted message.

-Kr	Outputs key analysis results as files, additionally poker test is enabled
	and outputs are shown visually.
-L	Enables or disables developer logs. Only enable this if you are having an
	issue and please submit the logs.
		0 Developer Logs Disabled
		1 Developer Logs Enabled
		Default: 0

-n 	New file output followed with a output file name. This doesn't overwrite
	the input plaintext instead writes to the given file name.	

