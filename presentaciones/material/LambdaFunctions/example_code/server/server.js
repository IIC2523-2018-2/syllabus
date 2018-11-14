const express = require('express')
const app = express()

const content = require('../index.js')

const work = (time) => {
    return new Promise(resolve => {
        for (var i = 0; i < time*1000000; i++);
        resolve();
    })
}

app.get('/', async (req, res) => {
    await work(500);
    res.send("Hello World")
})

app.listen(3000, () => console.log('Example app listening on port 3000!'))