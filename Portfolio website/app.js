// targeting the menus
const menu = document.querySelector('#mobile-menu');
const menuLinks = document.querySelector('.navbar__menu');

menu.addEventListener('click', function(){
    menu.classList.toggle('is-active');
    menuLinks.classList.toggle('active');
});

const verses = ["Genesis 23:6",
                "Genesis 34:22",
                "Exodus 17:7",
                "Exodus 34:9",
                "Deuteronomy 31:17",
                "Joshua 9:7",
                "Joshua 9:22",
                "Joshua 22:19",
                "Joshua 22:31",
                "Judges 18:25",
                "1 Samuel 4:3",
                "1 Kings 5:6",
                "Job 34:37",
                "Psalms 74:9",
                "Proverbs 1:14",
                "Isaiah 33:14",
                "Micah 3:11",
                "Luke 1:1",
                "Luke 7:16",
                "John 1:14",
                "Acts 1:21",
                "Acts 15:7",];
const random = Math.floor(Math.random() * verses.length);
document.getElementById("verse").innerHTML = verses[random];
document.getElementById("verse").href = "https://www.google.com/search?q=" + verses[random] + " KJV";