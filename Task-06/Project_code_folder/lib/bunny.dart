import 'package:flame/components.dart';
import 'package:game/directions.dart';

class Bunnyplayer extends SpriteComponent with HasGameRef {
  Direction direction = Direction.none;

  @override
  void update(double dt) {
    super.update(dt);
    updatePosition(dt);
  }

  updatePosition(double dt) {
    switch (direction) {
      case Direction.up:
        position.y--;
        break;
      case Direction.down:
        position.y++;
        break;
      case Direction.left:
        position.x--;
        break;
      case Direction.right:
        position.x++;
        break;
      case Direction.none:
        break;
    }
  }

  Bunnyplayer() : super(size: Vector2(150,150), position: Vector2(5, 5));
  @override
  Future<void> onLoad() async {
    super.onLoad();
    sprite = await gameRef.loadSprite('bunny.png');
    //position = Vector2(5, 5);
  }
}
