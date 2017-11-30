# DISTANCE VECTOR SIMULATION

## IF-3130 Jaringan Komputer

Nama Kelompok : Bareng yuk? Ayuk

Anggota :

1. 13515014 - Mokhammad Ferdi Ghozali
1. 13515029 - Finiko Kasula Novenda
1. 13515086 - M. iqbal Al Khowarizmi

## Petunjuk penggunaan program

1. Buka command prompt pada root folder.
1. Masukkan command 'make' untuk kompilasi program.
1. Jalankan main pada folder src.

## Penjelasan Program

Kami melakukan simulasi sebuah node dengan membuat array Node yang tiap Nodenya menyimpan informasi idnya, routingTable dan tetangganya. Lalu, tiap node akan saling berkomunikasi menyebarkan routing tabelnya melalui skenario yang telah disediakan.

### > struct Node

struct Node akan berisi id, neighbors, routeTable, dan neighborCounter.
Node ini akan merepresentasikan 1 buah node pada jaringan.
id akan mendefinisikan id node untuk identifikasi node.
neighbors akan berisi semua id node tetangganya yang terhubung langsung.
routeTable berisi distance, dan nextHop untuk tiap node.
neighborCounter untuk penanda indeks terakhir dari tabel neighbors yang telah terisi.

### > initializeNodes

Prosedur ini akan melakukan inisialisasi semua node yang akan diproses. Node yang terdefinisi adalah node dengan batasan 1 sampai N.

### > setEdges

Prosedur ini akan melakukan setting pada edges pada jaringan. Node yang saling terhubung akan didefinisikan disini menggunakan connectNode.

### > connectNode

Prosedur ini akan melakukan set neighbor pada node yang terhubung langsung. Dia akan menambahkan neighbor pada kedua node menggunakan addNeighbor.

### > addNeighbor

addNeighbor akan menambahkan node neighbor pada nodenya sekarang. Setelah itu, akan dilakukan update route tabel pada nodenya. Hal ini dilakukan dengan updateRouteTable.

### > updateRouteTable

Prosedur ini akan melakukan update terhadap route table. Dia akan mengubah nilai pada routeTable index tertentu sesuai dengan distance dan nextHop yang dimasukkan.

### > readAndExecuteScenarios

Prosedur ini akan membaca skenario yang akan dilakukan dan melakukan eksekusi skenario. Eksekusi skenario dilakuka dengan menggunakan shareInformation.

### > shareInformation

Prosedur ini akan melakukan update route table dari input node pengirim ke node tujuan. Node tujuan akan mengupdate route tabelnya bila beberapa syarat terpenuhi. Yaitu sebagai berikut :

1. Informasi route tidak mengarah ke dirinya sendiri.
1. Bukan merupakan tetangga yang terhubung langsung.
1. Nilai referensi distance dari pengirim lebih besar dari 0.
1. Distance dari routing tabel tujuan adalah -1 atau distancenya lebih besar dari informasi.
1. nextHop pengirim lebih kecil dari nextHop milik node penerima.

Proses update dilakuka dengan updateRouteTable.

## Pembagian Tugas

1. Mokhmammad Ferdi Ghozali mengerjakan fungsi setEdges, connectNodes, addNeighbor dan updateRouteTable.
1. Finiko Kasula Novenda mengerjakan fungsi searchNode, printRouteTable, setEdges, connectNodes, addNeighbor, updateRouteTable dan shareInformation.
1. M. Iqbal Al Khowarizmi mengerjakan fungsi readNodeAndEdgeCount, initializeNodes, readScenarioCount, readAndExecuteScenarios, shareInformation dan isNeighbor.

## Jawaban Pertanyaan

1. Apakah perbedaan dari routing protocol distance-vector dan link state? Manakah yang lebih baik untuk digunakan?

Distance-vector protocol adalah routing protocol yang tiap nodenya menyebarkan informasi routing table ke node lain. Routing table ini berisi informasi tentang node yang bisa dicapai, jaraknya serta melalui perantara node mana node tersebut dapat dicapai. Dalam rentang waktu tertentu, akan dilakukan update routing table dari tiap node. Update ini dilakukan dengan tiap node menyebarkan informasi routing tablenya pada node tetangganya yang terhubung langsung. Bila ternyata ditemukan jarak yang lebih pendek, maka data jarak ke node tersebut serta perantaranya akan diubah. Jika ternyata jaraknya sama, maka akan dipakai node yang memiliki id node terendah. Untuk node yang tidak diketahui jaraknya, maka jarak ke node tersebut akan diset tidak terhingga.
Link state protocol adalah routing protocol yang tiap nodenya menyebarkan informasi keterhubungan satu node dengan node lainnya. Informasi tersebut kemudian akan diolah sehingga membentuk routing table tiap node. Routing table ini tidak disebarkan tiap node. Pada awalnya, tiap node akan menyebarkan informasi pada node tetangganya yang terhubung langsung saja. Setelah itu, dia akan mulai menyebarkan link-state advertisement yang berisi informasi node yang membuatnya, semua node yang terhubung langsung dengannya dan sequence number yang menyatakan versi dari link-state advertisement. Lalu, masing - masing node akan membuat map berupa graph dari node.
Link state protocol lebih baik digunakan daripada distance-vector karena tiap node akan mengetahui map keterhubungannya. Bila terdapat perubahan pada map, maka link state dapat mengatasinya dengan lebih baik karena tiap node dapat mengetahui map serta jalur alternatifnya. Sedangkan pada distance vector, bila terjadi perubahan, maka akan sulit untuk melakukan update routing table pada tiap node. Meskipun link state protocol lebih kompleks dan memakan banyak memori, namun link state jauh lebih adaptif terhadap perubahan.

1. Pada implementasinya saat ini manakah yang lebih banyak digunakan, distance-vector atau  link state? Kenapa?

Untuk saat ini, link state lebih banyak digunakan. Hal ini karena meskipun jauh lebih kompleks, berat prosesnya dan memakan banyak memori, namun dengan perkembangan teknologi saat ini, hal - hal terkait kalkulasi dan memoripun dapat teratasi. Sehingga, link state banyak dipakai belakangan ini. Meskipun memang masih terdapat pemakaian menggunakan distance-vector. Salah satu protocol yang menggunakan link state adalah OSPF (Open Shortest Path First) yang merupakan non-proprietary Internal Gateway Protocol. Salah satu protocol yang menggunakan distance-vector adalah EIRGP (Enhanced Interior Gateway Protocol).
