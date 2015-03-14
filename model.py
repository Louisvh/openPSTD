########################################################################
# #
# This file is part of openPSTD.                                       #
#                                                                      #
# openPSTD is free software: you can redistribute it and/or modify     #
# it under the terms of the GNU General Public License as published by #
# the Free Software Foundation, either version 3 of the License, or    #
# (at your option) any later version.                                  #
#                                                                      #
# openPSTD is distributed in the hope that it will be useful,          #
# but WITHOUT ANY WARRANTY; without even the implied warranty of       #
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the        #
# GNU General Public License for more details.                         #
#                                                                      #
# You should have received a copy of the GNU General Public License    #
# along with openPSTD.  If not, see <http://www.gnu.org/licenses/>.    #
#                                                                      #
########################################################################

import json
import argparse
import tempfile

__author__ = 'michiel'


class model:
    def __init__(self):
        self.SceneDesc = None
        self.Simulation = None
        self.AppConfig = None
        self.Args = None

        self.SceneDescChanged = []
        self.SimulationChanged = []

        # parse arguments of the command line
        parser = argparse.ArgumentParser(prog="openPSTD", description="Stand-alone application openPSTD")
        parser.add_argument('-c', '--config', action="store", help="The configuration file",
                            default="configuration.json")
        self.Args = parser.parse_args()

        # load configuration
        self._load_config()

    def _load_config(self):
        f = open(self.Args.config, 'r')
        self.AppConfig = json.load(f)
        f.close()

    def get_calculation_directory(self):
        if self.AppConfig['working_dir'] is None:
            return tempfile.gettempdir()
        else:
            return self.AppConfig['working_dir']