import sys

from colorama import init
init(strip=not sys.stdout.isatty()) # strip colors if stdout is redirected
from termcolor import cprint 
from pyfiglet import figlet_format

#isometric1
#starwars
cprint(figlet_format(raw_input(), font='isometric1'),
		       'orange', 'on_pink', attrs=['bold'])
