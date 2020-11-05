QString LUNDTab::load_doc()
{
	return
	"<html>"
	"<STYLE TYPE=\"text/css\">"
	"<!--"
	".pretty-table"
	"{"
	"	padding: 0;"
	"	margin: 0;"
	"	border-collapse: collapse;"
	"	border: 1px solid #333;"
	"	font-family: \"Trebuchet MS\", Verdana, Arial, Helvetica, sans-serif;"
	"	font-size: 0.8em;"
	"	color: #000;"
	"	background: #bcd0e4;"
	"}"
	".pretty-table caption"
	"{"
	"	caption-side: bottom;"
	"	font-size: 0.9em;"
	"	font-style: italic;"
	"	text-align: right;"
	"	padding: 0.5em 0;"
	"}"
	".pretty-table th, .pretty-table td"
	"{"
	"	border: 1px dotted #666;"
	"	padding: 0.5em;"
	"	text-align: left;"
	"	color: #632a39;"
	"}"
	".pretty-table th[scope=col]"
	"{"
	"	color: #000;"
	"	background-color: #8fadcc;"
	"	text-transform: uppercase;"
	"	font-size: 0.9em;"
	"	border-bottom: 2px solid #333;"
	"	border-right: 2px solid #333;"
	"}"
	".pretty-table th+th[scope=col]"
	"{"
	"	color: #fff;"
	"	background-color: #7d98b3;"
	"	border-right: 1px dotted #666;"
	"}"
	".pretty-table th[scope=row]"
	"{"
	"	background-color: #b8cfe5;"
	"	border-right: 2px solid #333;"
	"}"
	"--->"
	"</STYLE>"
	"</head>"
	"<body>"
	"<center>"
	"<h2> LUND Format</h2>"
	"</center>"
	"<br>"
	"The LUND format is part of the JetSet and Pythia packages from CERN."
	"The full manual can be found at: <br> http://home.thep.lu.se/~torbjorn/pythia/lutp0613man2.pdf<br>"
	"<br>In the table below, the bold variables are the only one actually used by geant4. The remaining"
	"<b> UD </b> = User Defined variables can be filled with custom information. The names reported here "
	"are merely suggestions. All variables are saved in the output stream, even the ones not used.<br>"
	"<table cellsize=20>"
	"<tr><td>"
	"<table class=\"pretty-table\">"
	"<caption>Header Infos</caption>"
	"<tr><th scope=\"col\" >Column</th>"
	"    <th scope=\"col\" >Quantity</th></tr>"
	"<tr><th scope=\"row\">1 </th>              <td><b>Number of particles</b></td></tr>"
	"<tr><th scope=\"row\">2 </th>              <td>(UD) Number of target nucleons</td></tr>"
	"<tr><th scope=\"row\">3 </th>              <td>(UD) Number of target protons</td></tr>"
	"<tr><th scope=\"row\">4 </th>              <td>(UD) Target Polarization</td></tr>"
	"<tr><th scope=\"row\">5 </th>              <td><b>Beam Polarization</b></td></tr>"
	"<tr><th scope=\"row\">6 </th>              <td>(UD) <i>x</td></tr>"
	"<tr><th scope=\"row\">7 </th>              <td>(UD) <i>y</td></tr>"
	"<tr><th scope=\"row\">8 </th>              <td>(UD) <i>W</td></tr>"
	"<tr><th scope=\"row\">9 </th>              <td>(UD) <i>Q2</td></tr>"
	"<tr><th scope=\"row\">10</th>              <td>(UD) <i>nu</i></td></tr>"
	"</table>"
	"</td>"
	"<td>"
	"<table class=\"pretty-table\">"
	"<caption>Particle Infos</caption>"
	"<tr><th scope=\"col\">Column</th>"
	"    <th scope=\"col\">Quantity</th></tr>"
	"<tr><th scope=\"row\">1 </th>             <td><b>index</b></td></tr>"
	"<tr><th scope=\"row\">2 </th>             <td>(UD) charge</td></tr>"
	"<tr><th scope=\"row\">3 </th>             <td><b>type</b></td></tr>"
	"<tr><th scope=\"row\">4 </th>             <td><b>particle id</b></td></tr>"
	"<tr><th scope=\"row\">5 </th>             <td>(UD) parent id</td></tr>"
	"<tr><th scope=\"row\">6 </th>             <td>(UD) daughter</td></tr>"
	"<tr><th scope=\"row\">7 </th>             <td><b>p<sub>x</sub></b></td></tr>"
	"<tr><th scope=\"row\">8 </th>             <td><b>p<sub>y</sub></b></td></tr>"
	"<tr><th scope=\"row\">9 </th>             <td><b>p<sub>z</sub></b></td></tr>"
	"<tr><th scope=\"row\">10</th>             <td>(UD) particle energy</td></tr>"
	"<tr><th scope=\"row\">11</th>             <td>(UD) mass</td></tr>"
	"<tr><th scope=\"row\">12</th>             <td><b>x vertex</td></tr>"
	"<tr><th scope=\"row\">13</th>             <td><b>y vertex</td></tr>"
	"<tr><th scope=\"row\">14</th>             <td><b>z vertex</td></tr>"
	"</table>"
	"</td></tr>"
	"</table>"
	"<br><br>"
	"<h3> Example of 2 DVCS events (eP&gamma;)"
	"<br>"
	"<small><pre>"
	"3  1.  1.  0 -1 0.209   0.336   6.373   1.448  -1.000<br>"
	"  1 -1.  1   11  0  0    0.9636  -0.1675   7.2357   7.3015   0.0005   0.0000 0.0000 0.0000<br>"
	"  2  1.  1 2212  0  0   -0.6536   0.0604   0.3367   1.1935   0.9383   0.0000 0.0000 0.0000<br>"
	"  3  0.  1   22  0  0   -0.3100   0.1071   3.4276   3.4432   0.0000   0.0000 0.0000 0.0000<br>"
	"3  1.  1.  0 -1 0.259   0.214   4.148   1.143  -1.000<br>"
	"  1 -1.  1   11  0  0   -0.0203   0.9464   8.5979   8.6498   0.0005   0.0000 0.0000 0.0000<br>"
	"  2  1.  1 2212  0  0   -0.0388  -0.2442   0.2194   0.9948   0.9383   0.0000 0.0000 0.0000<br>"
	"  3  0.  1   22  0  0    0.0591  -0.7022   2.1827   2.2936   0.0000   0.0000 0.0000 0.0000<br>"
	"</pre><small>"
	" </body></html>";
}





