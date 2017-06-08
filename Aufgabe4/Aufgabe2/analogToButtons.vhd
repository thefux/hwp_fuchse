-- analogToButtons
-- converts the reading of the adc into the corresponding button


library ieee;
use ieee.std_logic_1164.all;
use ieee.numeric_std.all;

entity analogToButtons is port(
	analogIn : in std_logic_vector(11 downto 0);
	
	Led: out std_logic_vector(5 downto 0)
);
end analogToButtons;


architecture behavior of analogToButtons is


begin
	-- TODO: add your code here

	Led(5) <= '1' when unsigned(analogIn) > 3500;
	Led(4) <= '1' when (unsigned(analogIn) > 3000 and unsigned(analogIn) < 3500) else '0';
	Led(3) <= '1' when (unsigned(analogIn) > 2500 and unsigned(analogIn) < 3000) else '0';
	Led(2) <= '1' when (unsigned(analogIn) > 1700 and unsigned(analogIn) < 2500) else '0';
	Led(1) <= '1' when (unsigned(analogIn) > 850 and unsigned(analogIn) < 1700) else '0';
	Led(0) <= '1' when (unsigned(analogIn) > 0 and unsigned(analogIn) < 850) else '0';
	
	
	
		
		
end behavior;
