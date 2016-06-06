from cassandra.cluster import Cluster
import uuid, sys

class CassandraMenu:

    def __init__(self):
        self.cluster = Cluster(['172.17.0.2', '172.17.0.3', '172.17.0.4'])
        self.session = self.cluster.connect('musicstore')
        self.menu()

    def menu(self):
        while True:
            try:
                print("1: Show Playlists")
                print("2: Insert into Playlists")
                print("3: Search Playlists")
                print("0: exit")
                selection = int(input("Select: "))

                if selection == 1:
                    self.show()
                elif selection == 2:
                    self.insert()
                elif selection == 3:
                    self.search()
                elif selection == 0:
                    break

            except:
                print("Invalid input")

    def show(self):
        rows = self.session.execute("SELECT id, album, artist, title FROM playlists")

        for pl_row in rows:
            print(pl_row.id, pl_row.album, pl_row.artist, pl_row.title)

        print("")

    def insert(self):
        try:

            playlist = input("Enter Playlist ID: ")
            if len(playlist) == 0:
                playlist = uuid.uuid4()
            else:
                playlist = uuid.UUID(playlist)

            order = int(input("Enter Song Order: "))
            song = input("Enter Song: ")
            artist = input("Enter Artist: ")
            album = input("Enter Album: ")

            self.session.execute(
                """
                INSERT INTO playlists (id, song_order, song_id, title, artist, album)
                VALUES (%s, %s, %s, %s, %s, %s)
                """,
                (playlist, order, uuid.uuid4(), song, artist, album)
            )
        except:
            print("Invalid input\n")

    def search(self):
        try:
            artist = input("Enter Artist: ")
            rows = self.session.execute("SELECT * FROM playlists WHERE artist='{0}'".format(artist))
            for pl_row in rows:
                print(pl_row.id, pl_row.album, pl_row.artist, pl_row.title)

        except Exception as e:
            print(e)


if __name__ == "__main__":
    CassandraMenu()