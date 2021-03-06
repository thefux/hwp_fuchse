-- Copyright (C) 2016  Intel Corporation. All rights reserved.
-- Your use of Intel Corporation's design tools, logic functions 
-- and other software and tools, and its AMPP partner logic 
-- functions, and any output files from any of the foregoing 
-- (including device programming or simulation files), and any 
-- associated documentation or information are expressly subject 
-- to the terms and conditions of the Intel Program License 
-- Subscription Agreement, the Intel Quartus Prime License Agreement,
-- the Intel MegaCore Function License Agreement, or other 
-- applicable license agreement, including, without limitation, 
-- that your use is for the sole purpose of programming logic 
-- devices manufactured by Intel and sold by Intel or its 
-- authorized distributors.  Please refer to the applicable 
-- agreement for further details.

-- ***************************************************************************
-- This file contains a Vhdl test bench template that is freely editable to   
-- suit user's needs .Comments are provided in each section to help the user  
-- fill out necessary details.                                                
-- ***************************************************************************
-- Generated on "06/06/2017 16:55:33"
                                                            
-- Vhdl Test Bench template for design  :  fulladder2bit
-- 
-- Simulation tool : ModelSim-Altera (VHDL)
-- 

LIBRARY ieee;                                               
USE ieee.std_logic_1164.all;                                

ENTITY fulladder2bit_vhd_tst IS
END fulladder2bit_vhd_tst;
ARCHITECTURE fulladder2bit_arch OF fulladder2bit_vhd_tst IS
-- constants                                                 
-- signals                                                   
SIGNAL A0 : STD_LOGIC;
SIGNAL A1 : STD_LOGIC;
SIGNAL B0 : STD_LOGIC;
SIGNAL B1 : STD_LOGIC;
SIGNAL carryIN : STD_LOGIC;
SIGNAL carryOUT : STD_LOGIC;
SIGNAL sum0 : STD_LOGIC;
SIGNAL sum1 : STD_LOGIC;
COMPONENT fulladder2bit
	PORT (
	A0 : IN STD_LOGIC;
	A1 : IN STD_LOGIC;
	B0 : IN STD_LOGIC;
	B1 : IN STD_LOGIC;
	carryIN : IN STD_LOGIC;
	carryOUT : OUT STD_LOGIC;
	sum0 : OUT STD_LOGIC;
	sum1 : OUT STD_LOGIC
	);
END COMPONENT;
BEGIN
	i1 : fulladder2bit
	PORT MAP (
-- list connections between master ports and signals
	A0 => A0,
	A1 => A1,
	B0 => B0,
	B1 => B1,
	carryIN => carryIN,
	carryOUT => carryOUT,
	sum0 => sum0,
	sum1 => sum1
	);
init : PROCESS                                               
-- variable declarations                                     
BEGIN                                                        
        -- code that executes only once 
			carryIN <= '0';
			A0 <= '0';
			B0 <= '0';
			A1 <= '0';
			B1 <= '0';
			wait for 20 ns;
			
			carryIN <= '0';
			A0 <= '1';
			B0 <= '0';
			A1 <= '0';
			B1 <= '0';
			
			carryIN <= '0';
			A0 <= '0';
			B0 <= '1';
			A1 <= '0';
			B1 <= '0';
			wait for 20 ns;
			
			carryIN <= '0';
			A0 <= '1';
			B0 <= '1';
			A1 <= '0';
			B1 <= '0';
			wait for 20 ns;
			
			
			carryIN <= '0';
			A0 <= '0';
			B0 <= '0';
			A1 <= '1';
			B1 <= '0';
			wait for 20 ns;
			
			
			carryIN <= '0';
			A0 <= '1';
			B0 <= '0';
			A1 <= '1';
			B1 <= '0';
			wait for 20 ns;
		  
			carryIN <= '0';
			A0 <= '0';
			B0 <= '1';
			A1 <= '1';
			B1 <= '0';
			wait for 20 ns;
		
			carryIN <= '0';
			A0 <= '1';
			B0 <= '1';
			A1 <= '1';
			B1 <= '0';
			wait for 20 ns;
			
			carryIN <= '0';
			A0 <= '0';
			B0 <= '0';
			A1 <= '0';
			B1 <= '1';
			wait for 20 ns;
			
			carryIN <= '0';
			A0 <= '1';
			B0 <= '0';
			A1 <= '0';
			B1 <= '1';
			wait for 20 ns;
			
			carryIN <= '0';
			A0 <= '0';
			B0 <= '1';
			A1 <= '0';
			B1 <= '1';
			wait for 20 ns;
			
			carryIN <= '0';
			A0 <= '1';
			B0 <= '1';
			A1 <= '0';
			B1 <= '1';
			wait for 20 ns;
			
			carryIN <= '0';
			A0 <= '0';
			B0 <= '0';
			A1 <= '1';
			B1 <= '1';
			wait for 20 ns;
			
			carryIN <= '0';
			A0 <= '1';
			B0 <= '0';
			A1 <= '1';
			B1 <= '1';
			wait for 20 ns;
			
			carryIN <= '0';
			A0 <= '1';
			B0 <= '1';
			A1 <= '1';
			B1 <= '1';
			wait for 20 ns;
WAIT;                                                       
END PROCESS init;                                           
always : PROCESS                                              
-- optional sensitivity list                                  
-- (        )                                                 
-- variable declarations                                      
BEGIN                                                         
        -- code executes for every event on sensitivity list  
WAIT;                                                        
END PROCESS always;                                          
END fulladder2bit_arch;
