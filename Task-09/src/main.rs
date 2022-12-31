use csv;
use std::fs::OpenOptions;
fn main() {
 let response = reqwest::blocking::get(
    "https://crypto.com/price"
 )
 .unwrap()
 .text()
 .unwrap();

 let document = scraper::Html::parse_document(&response);
 let mut rows = Vec::new();

 let name = scraper::Selector::parse("div.css-ttxvk0>p").unwrap();
 let names = document.select(&name).map(|x| x.inner_html());
 names
        .zip(1..51)
        .for_each(|(item, _number)|{
            let row1 = vec![item];
            rows.push(row1);
              });

let price = scraper::Selector::parse("div.css-b1ilzc").unwrap();
let prices  = document.select(&price).map(|x| x.inner_html());
prices
  .zip(1..51)
.for_each(|(item,number)| {
  rows[number-1].push(item);
});


let change_24 = scraper::Selector::parse("td.css-1b7j986>p").unwrap();
let change_24_values = document.select(&change_24).map(|x| x.inner_html());
change_24_values
.zip(1..51)
.for_each(|(item,number)| {
  rows[number-1].push(item);
});


let mut i = 0;
let volume_24 = scraper::Selector::parse("td.css-1nh9lk8").unwrap();
let volume_24_values = document.select(&volume_24).map(|x| x.inner_html());
volume_24_values
.zip(1..101)
.for_each(|(item,number)|{
if number%2==0{
  rows[i].push(item);
  i=i+1;
}
else{
    rows[i].push(item);
}
            
});

  let file = OpenOptions::new()
        .write(true)
        .create(true)
        .open("test.csv")
        .unwrap();
let mut wtr = csv::Writer::from_writer(file);
wtr.write_record(&["Name","Price","24 Hour Change","24 H Volume","Market Cap"]).unwrap();


for row in rows.iter(){
  wtr.write_record(row).unwrap();
}

}

