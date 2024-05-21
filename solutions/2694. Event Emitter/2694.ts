// Time complexity: O(1) / O(m)
// Space complexity: O(n) / O(m)
type Callback = (...args: any[]) => any;
type Subscription = {
  unsubscribe: () => void;
};

class EventEmitter {
  private eventToCallbacks: Map<string, Callback[]>;

  constructor() {
    this.eventToCallbacks = new Map();
  }

    subscribe(eventName: string, callback: Callback): Subscription {
    if (!this.eventToCallbacks.has(eventName))
      this.eventToCallbacks.set(eventName, []);

    const callbacks = this.eventToCallbacks.get(eventName);
    callbacks?.push(callback);

    return {
      unsubscribe: () => {
        const index = callbacks?.indexOf(callback);
        if (index !== undefined && index !== -1) {
          callbacks?.splice(index, 1);
        }
      },
    };
  }

  emit(eventName: string, args: any[] = []): any[] {
    const callback = this.eventToCallbacks.get(eventName);
    if (callback === undefined) {
      return [];
    }

    return callback.map((callback) => callback(...args));
  }
}