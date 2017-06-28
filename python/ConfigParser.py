import ConfigParser, string, os, sys

# Device codes for cRIO-9035(Sync) and cRIO-9039 (Sync)
cRIO_903x_sync = ["7875", "7878"]
# Device codes for ic317x
IC_317x = ["77AD", "7828", "787E"]

def generate_tsn_config_file(config_file):
	cf = ConfigParser.ConfigParser()

	for element in cRIO_903x_sync:
		cf.add_section(element)
		cf.set(element, 'txISRTimeConsumeInNs', "31184")
		cf.set(element, 'rxDMATimeInNs', "12596")
		cf.set(element, 'memoryCopyTimePerTimeInNs', "1911")
		cf.set(element, 'prefetchTimeInNs', "38000")
		cf.set(element, 'launchLatencyInNs', "1817")

	for element in IC_317x:
		cf.add_section(element)
		cf.set(element, 'txISRTimeConsumeInNs', "11006")
		cf.set(element, 'rxDMATimeInNs', "12596")
		cf.set(element, 'memoryCopyTimePerTimeInNs', "319")
		cf.set(element, 'prefetchTimeInNs', "38000")
		cf.set(element, 'launchLatencyInNs', "1817")

	config_file = open(config_file, "wb+")
	cf.write(config_file)
	config_file.close()

if __name__ =='__main__':
   generate_tsn_config_file(sys.argv[1])
