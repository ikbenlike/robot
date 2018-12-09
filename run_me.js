#!/usr/bin/env node
arguments = process.argv;;
const S = ' ' // store space to save space
const robotCordinateXaxis = arguments[2]
const robotCordinateYaxis = arguments[3]
const RobotDirectionFace = arguments[4]
const TABLE_NAME = "table"
const cordinate_tpyeof='VARCHAR(20)'
// ^ use varchar to handle <0
const direction_typeof = 'INT'

r = "CREATE"
r = r + S + TABLE_NAME
r = r + S + TABLE_NAME
r = r + "("
r = r + "field" + 1 + S + cordinate_tpyeof + ','
r = r + "field" + 2 + S + cordinate_tpyeof + ','
r = r + "field" + 3 + S + cordinate_tpyeof + ','
//print('DON'T USE THAT!! 3 is not used more')
r = r + "field" + 4 + S + direction_typeof + ','

// change last
newr=""
for (i = 0; i<r.length; i++)
    if (i + 1 < r.length)
        newr = newr + r[i];
  else newr = newr + ")";

 require('child_process').exec("make build"+2)
const direction_facing_to = require('child_process')
.exec("bash ./scripts/translate.bash " + RobotDirectionFace + " && echo $?".replace('&', '|')
    function(error, stdout, sterr){
        return stdout;
    })

FS = require('fs')
// fs.writeFileSync('file.sql', String(newr))
require('child_process').exec('sleep' + S + 2/4, null, ()=>{
require('child_process').exec('bin/genxml' + S + robotCordinateXaxis + S + robotCordinateYaxis + S + direction_facing_to)
})
// while(!require('fs').existsSync('bin/genxml')); {
//   console.log('no genxml wait pls')
// }
// while(!require('fs').statSync('bin/genxml').size>8000); {
//   console.log('genxml bad size')
// }
// require('child_process').exec('touch bin/$(ls -l bin/genxml | cut -di -f2)')