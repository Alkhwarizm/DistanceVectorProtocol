# DISTANCE VECTOR SIMULATION

## IF-3130 Jaringan Komputer

Nama Kelompok : Bareng yuk? Ayuk
Anggota :

1. 13515014 - Mokhammad Ferdi Ghozali
1. 13515029 - Finiko Kasula Novenda
1. 13515086 - M. iqbal Al Khowarizmi

## Petunjuk penggunaan program

1. Buka command prompt pada root folder.
1. Masukkan command 'make' untuk menjalankan program.

## Bagaimana anda mensimulasikan sebuah node dalam program anda? Bagaimana proses pengiriman pesan antar node terjadi?     Jelaskan dengan menggunakan nama fungsi dan/atau struktur data yang anda gunakan

Kami melakukan simulasi sebuah node dengan membuat.

## Pembagian Tugas

1. Mokhmammad Ferdi Ghozali mengerjakan fungsi
1. Finiko Kasula Novenda mengerjakan fungsi
1. M. Iqbal Al Khowarizmi mengerjakan fungsi

## Jawaban Pertanyaan

1. Apakah perbedaan dari routing protocol distance-vector dan link state? Manakah yang lebih baik untuk digunakan?

Distance-vector protocol adalah routing protocol yang tiap nodenya menyebarkan informasi routing table ke node lain. Routing table ini berisi informasi tentang node yang bisa dicapai, jaraknya serta melalui perantara node mana node tersebut dapat dicapai. Dalam rentang waktu tertentu, akan dilakukan update routing table dari tiap node. Update ini dilakukan dengan tiap node menyebarkan informasi routing tablenya pada node tetangganya yang terhubung langsung. Bila ternyata ditemukan jarak yang lebih pendek, maka data jarak ke node tersebut serta perantaranya akan diubah. Jika ternyata jaraknya sama, maka akan dipakai node yang memiliki id node terendah. Untuk node yang tidak diketahui jaraknya, maka jarak ke node tersebut akan diset tidak terhingga.
Link state protocol adalah routing protocol yang tiap nodenya menyebarkan informasi keterhubungan satu node dengan node lainnya. Informasi tersebut kemudian akan diolah sehingga membentuk routing table tiap node. Routing table ini tidak disebarkan tiap node. Pada awalnya, tiap node akan menyebarkan informasi pada node tetangganya yang terhubung langsung saja. Setelah itu, dia akan mulai menyebarkan link-state advertisement yang berisi informasi node yang membuatnya, semua node yang terhubung langsung dengannya dan sequence number yang menyatakan versi dari link-state advertisement. Lalu, masing - masing node akan membuat map berupa graph dari node.
Link state protocol lebih baik digunakan daripada distance-vector karena tiap node akan mengetahui map keterhubungannya. Bila terdapat perubahan pada map, maka link state dapat mengatasinya dengan lebih baik karena tiap node dapat mengetahui map serta jalur alternatifnya. Sedangkan pada distance vector, bila terjadi perubahan, maka akan sulit untuk melakukan update routing table pada tiap node. Meskipun link state protocol lebih kompleks dan memakan banyak memori, namun link state jauh lebih adaptif terhadap perubahan.

1. Pada implementasinya saat ini manakah yang lebih banyak digunakan, distance-vector atau  link state? Kenapa?

Untuk saat ini, link state lebih banyak digunakan. Hal ini karena meskipun jauh lebih kompleks, berat prosesnya dan memakan banyak memori, namun dengan perkembangan teknologi saat ini, hal - hal terkait kalkulasi dan memoripun dapat teratasi. Sehingga, link state banyak dipakai belakangan ini. Meskipun memang masih terdapat pemakaian menggunakan distance-vector. Salah satu protocol yang menggunakan link state adalah OSPF (Open Shortest Path First) yang merupakan non-proprietary Internal Gateway Protocol. Salah satu protocol yang menggunakan distance-vector adalah EIRGP (Enhanced Interior Gateway Protocol).