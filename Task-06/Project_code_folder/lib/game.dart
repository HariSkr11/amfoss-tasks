import 'dart:ui';
import 'package:flame/game.dart';
import 'bunny.dart';
import 'world.dart';
import 'directions.dart';

class BunnyGame extends FlameGame {
  Bunnyplayer _bunny = Bunnyplayer();
  World _world = World();
  onArrowKeyChanged(Direction direction) {
    _bunny.direction = direction;
  }

  @override
  Future<void> onLoad() async {
    final screenwidth = size[0];
    final screensize = size[1];
    final size1 = _bunny.size[1];
    print(size1);
    super.onLoad();

    await add(_world);
    await add(_bunny);
    _bunny.position = Vector2(0, screensize-size1+275);
    camera.followComponent(_bunny,
        worldBounds: Rect.fromLTRB(0, 0, _world.size.x, _world.size.y));
  }
}
